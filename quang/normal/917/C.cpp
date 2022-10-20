#include <bits/stdc++.h>

using namespace std;

const int N = 10, M = 100;
const long long INF = (long long)1e18 + 10;

inline bool getBit(int mask, int u) {
	return (mask >> u) & 1;
}

int n, x, k, q;
int c[N];
map<int, int> m;
vector<int> li;
int id[1 << 8];
int cntMask;

struct Matrix {
	long long a[M][M];

	Matrix(long long dia = INF) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < M; j++) {
				a[i][j] = INF;
				if (i == j) a[i][j] = dia;
			}
		}
	}

	Matrix operator * (const Matrix &u) const {
		Matrix res;
		for (int i = 0; i < cntMask; i++) {
			for (int j = 0; j < cntMask; j++) {
				for (int k = 0; k < cntMask; k++) {
					res.a[i][j] = min(res.a[i][j], a[i][k] + u.a[k][j]);
				}
			}
		}
		return res;
	}

	Matrix operator ^ (int v) const {
		Matrix u = *this;
		Matrix res(0);
		while (v) {
			if (v & 1) {
				res = res * u;
			}
			u = u * u;
			v >>= 1;
		}
		return res;
	}

	void trace() {
		for (int i = 0; i < cntMask; i++) {
			for (int j = 0; j < cntMask; j++) {
				printf("%20lld ", a[i][j]);
			}
			printf("\n");
		}
	}
} B;

void init() {
	for (int i = 0; i < (1 << k); i++) {
		if (__builtin_popcount(i) == x) {
			li.push_back(i);
			id[i] = cntMask++;
		}
	}
	for (int i = 0; i < cntMask; i++) {
		if (li[i] % 2 == 0) {
			B.a[i][id[li[i] / 2]] = 0;
		} else {
			for (int j = 1; j <= k; j++) {
				if (!getBit(li[i], j)) {
					int newMask = li[i] | (1 << j);
					newMask >>= 1;
					B.a[i][id[newMask]] = c[j];
				}
			}
		}
	}	
}

Matrix turn(Matrix A, int u) {
	Matrix res;
	for (int i = 0; i < cntMask; i++) {
		if (li[i] % 2 == 0) {
			res.a[0][id[li[i] / 2]] = min(res.a[0][id[li[i] / 2]], A.a[0][i]);
		} else {
			for (int j = 1; j <= k; j++) {
				if (!getBit(li[i], j)) {
					int newMask = li[i] | (1 << j);
					newMask >>= 1;
					res.a[0][id[newMask]] = min(res.a[0][id[newMask]], A.a[0][i] + c[j] + m[u + j]);
				}
			}
		}
	}
	return res;
}

int main() {
	scanf("%d %d %d %d", &x, &k, &n, &q);
	vector<int> val;
	for (int i = 1; i <= k; i++) {
		scanf("%d", c + i);
	}
	val.push_back(1);
	val.push_back(n - x + 1);
	for (int i = 1; i <= q; i++) {
		int p, w;
		scanf("%d %d", &p, &w);
		m[p] = w;
		for (int j = -k; j <= 0; j++) {
			if (j + p > 1 && j + p < n - x + 1) {
				val.push_back(j + p);
			}
		}
	}
	sort(val.begin(), val.end());
	val.resize(unique(val.begin(), val.end()) - val.begin());
	init();
	Matrix A;
	A.a[0][0] = 0;
	for (int i = 1; i < val.size(); i++) {
		if (val[i] - val[i - 1] > 1) {
			A = A * (B ^ (val[i] - val[i - 1]));
		} else {
			A = turn(A, val[i - 1]);
		}
		// cout << val[i] << endl;
		// A.trace();
	}
	cout << A.a[0][0] << endl;
	return 0;
}