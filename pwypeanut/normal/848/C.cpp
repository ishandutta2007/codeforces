#include <bits/stdc++.h>
using namespace std;

int N, M, A[100005];
long long fw[2][100005];
set<int> occur[100005];
unordered_map< long long, long long> fw2;

void upd(int f, int p, int v) {
	p++;
	for (int i = p; i <= N; i += (i & (-i))) fw[f][i] += v;
}

long long qry(int f, int p) {
	p++;
	long long ans = 0;
	for (int i = p; i > 0; i -= (i & (-i))) ans += fw[f][i];
	return ans;
}

void upd2(int x, int y, int v) {
	x++;
	y++;
	for (int i = x; i <= N; i += (i & (-i))) {
		for (int j = y; j <= N; j += (j & (-j))) {
			fw2[(long long)i*(N+1)+j] += v;
		}
	}
}

long long qry2(int x, int y) {
	x++;
	y++;
	long long ans = 0;
	for (int i = x; i > 0; i-=(i&(-i))) {
		for (int j = y; j > 0; j -= (j & (-j))) {
			ans += fw2[(long long)i*(N+1)+j];
		}
	}
	return ans;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < N; i++) {
		occur[A[i]].insert(i);
	}
	for (int i = 0; i < N; i++) {
		set<int>::iterator it = occur[A[i]].lower_bound(i);
		if (it == occur[A[i]].begin()) continue;
		else {
			it--;
			upd(0, i, i - *it);
			upd2(*it, i, i - *it);
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a == 2) {
			b--;
			c--;
			long long ans = qry(0, c) - qry(0, b - 1);
			ans -= qry2(b - 1, c) - qry2(b - 1, b - 1);
			printf("%lld\n", ans);
		} else {
			b--;
			int orival = A[b];
			set<int>::iterator it = occur[orival].lower_bound(b);
			if (it != occur[orival].begin()) {
				it--;
				upd(0, b, *it - b);
				upd2(*it, b, *it - b);
				it++;
			}
			if (it != (--occur[orival].end())) {
				it++;
				upd(0, *it, b - *it);
				upd2(b, *it, b - *it);
				it--;
			}
			if (it != occur[orival].begin() && it != (--occur[orival].end())) {
				int bval, fval;
				it--;
				bval = *it;
				it++;
				it++;
				fval = *it;
				it--;
				upd(0, fval, fval - bval);
				upd2(bval, fval, fval - bval);
			}
			A[b] = c;
			occur[orival].erase(b);
			occur[c].insert(b);
			it = occur[c].lower_bound(b);
			if (it != occur[c].begin() && it != (--occur[c].end())) {
				int bval, fval;
				it--;
				bval = *it;
				it++;
				it++;
				fval = *it;
				it--;
				upd(0, fval, bval - fval);
				upd2(bval, fval, bval - fval);
			}
			if (it != occur[c].begin()) {
				it--;
				upd(0, b, b - *it);
				upd2(*it, b, b - *it);
				it++;
			}
			if (it != (--occur[c].end())) {
				it++;
				upd(0, *it, *it - b);
				upd2(b, *it, *it - b);
				it--;
			}
		}
	}
}