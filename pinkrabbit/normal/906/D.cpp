// Author : PinkRabbit

#include <cstdio>
#include <unordered_map> // c++11

typedef long long LL;
const int MN = 500005, MS = 20000005, MP = 1270608;

inline int R(LL x, int m) { return x < m ? x : x % m + m; }
inline int qPow(int b, int e, int m) {
	int a = 1;
	for (; e; e >>= 1, b = R((LL)b * b, m))
		if (e & 1) a = R((LL)a * b, m);
	return a;
}

std::unordered_map<int, int> mp;
inline int phi(int x) {
	if (mp.find(x) != mp.end()) return mp[x];
	int y = x, phi = y;
	for (int i = 2; i * i <= x; ++i) if (y % i == 0) {
		phi -= phi / i;
		while (y % i == 0) y /= i;
	} if (y > 1) phi -= phi / y;
	return mp[x] = phi;
}

int N, M, Q, A[MN];

int F(int l, int r, int m) {
	if (m == 1 || l > r || A[l] == 1) return 1;
	return qPow(R(A[l], m), F(l + 1, r, phi(m)), m);
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
	scanf("%d", &Q);
	while (Q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", F(l, r, M) % M);
	}
	return 0;
}