#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int M = 2000010;
const int MOD = 1000000007;

inline int add(int u, int v) {
    u += v;
    if (u >= MOD) {
        u -= MOD;
    }
    return u;
}

inline int sub(int u, int v) {
    u -= v;
    if (u < 0) {
        u += MOD;
    }
    return u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) {
            res = mul(res, u);
        }
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}

inline int inv(int u) {
    return power(u, MOD - 2);
}

int n;
int p[M];
int a[N];
int maxPower[M], cntMaxPower[M];

vector<pair<int, int> > getPrimeDivs(int u) {
	vector<pair<int, int> > res;
	while (u > 1) {
		int v = p[u];
		res.push_back(make_pair(v, 0));
		while (u % v == 0) {
			u /= v;
			res.back().second++;
		}
	}
	return res;
}

bool canAdd(int u) {
	vector<pair<int, int> > primeDivs = getPrimeDivs(u);
	for (auto v : primeDivs) {
		if (v.second > maxPower[v.first]) {
			return true;
		}
	}
	return false;
}

void add(int u) {
	vector<pair<int, int> > primeDivs = getPrimeDivs(u);
	for (auto v : primeDivs) {
		if (v.second == maxPower[v.first]) {
			cntMaxPower[v.first]++;
		} else if (v.second > maxPower[v.first]) {
			maxPower[v.first] = v.second;
			cntMaxPower[v.first] = 1;
		}
	}
}

int used[N];

bool canRemove(int u) {
	vector<pair<int, int> > primeDivs = getPrimeDivs(u);
	for (auto v : primeDivs) {
		if (v.second == maxPower[v.first] && cntMaxPower[v.first] == 1) {
			return false;
		}
	}
	return true;
}

void remove(int u) {
	vector<pair<int, int> > primeDivs = getPrimeDivs(u);
	for (auto v : primeDivs) {
		if (v.second == maxPower[v.first]) {
			cntMaxPower[v.first]--;
		}
	}
}

int main() {
	for (int i = 2; i < M; i++) {
		if (!p[i]) {
			for (int j = i; j < M; j += i) {
				if (!p[j]) {
					p[j] = i;
				}
			}
		}
	}

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	sort(a + 1, a + n + 1);
	int tail = 0;
	for (int i = n; i > 0; i--) {
		if (canAdd(a[i])) {
			add(a[i]);
			used[i] = 1;
		} else if (canAdd(a[i] - 1)) {
			used[i] = 2;
			add(a[i] - 1);
		} else {
			tail = 1;
		}
	}
	for (int i = n; i > 0; i--) {
		if (used[i] == 0) {
			continue;
		}
		int u = used[i] == 1 ? a[i] : a[i] - 1;
		if (canRemove(u)) {
			remove(u);
			tail = 1;
		}
	}
	int res = 1;
	for (int i = 1; i < M; i++) {
		if (p[i] == i) {
			res = mul(res, power(i, maxPower[i]));
		}
	}
	res = add(res, tail);
	cout << res << endl;
	return 0;
}