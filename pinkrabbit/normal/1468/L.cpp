#include <cstdio>
#include <cmath>
#include <vector>
#include <map>

const int MV = 1000005, MP = 78499;

bool ip[MV];
int p[MP], pc;
void Sieve(int N) {
	for (int i = 2; i <= N; ++i) {
		if (!ip[i]) p[++pc] = i;
		for (int j = 1, k; j <= pc; ++j) {
			if ((k = p[j] * i) > N) break;
			ip[k] = 1;
			if (i % p[j] == 0) break;
		}
	}
}

typedef long long LL;
const int MN = 50005;

int N, K, del[MN];
LL A[MN], tA[MN];
std::vector<int> V[MN];

int cnt;
std::map<int, int> mp;
int imp[MN], buk[MN], usd[MN], usdp[MN];
std::vector<int> V2[MN];

int main() {
	Sieve(1000000);
	scanf("%d%d", &N, &K);
	if (K == 1) return puts("0"), 0;
	for (int i = 1; i <= N; ++i) {
		scanf("%lld", &A[i]);
		LL x = A[i];
		for (int j = 1; x > 1 && j <= pc; ++j) if (x % p[j] == 0) {
			V[i].push_back(p[j]);
			while (x % p[j] == 0) x /= p[j];
		}
		if (x > 1) {
			if (x <= 1000000000) V[i].push_back((int)x);
			else {
				LL y = std::sqrt(x);
				while (y * y <= x) ++y;
				while (y * y > x) --y;
				if (y * y == x) V[i].push_back((int)y);
				else del[i] = 1, tA[i] = x;
			}
		}
	}
	for (int i = 1; i <= N; ++i) if (!del[i]) {
		int sz = (int)V[i].size();
		if (sz == 1) {
			int pr = V[i][0];
			if (!mp[pr]) imp[mp[pr] = ++cnt] = pr;
			int id = mp[pr];
			++buk[id];
		}
	}
	for (int i = 1; i <= N; ++i) if (del[i]) {
		LL x = tA[i];
		for (int j = 1; j <= cnt; ++j) if (buk[j] >= 2) {
			int pr = imp[j];
			if (x % pr == 0) {
				V[i].push_back(pr);
				while (x % pr == 0) x /= pr;
			}
		}
		if (x == 1) del[i] = 0;
	}
	for (int i = 1; i <= N; ++i) if (!del[i]) {
		int sz = (int)V[i].size(), ok = 1;
		for (int j = 0; j < sz; ++j) {
			int pr = V[i][j];
			if (!mp[pr]) ok = 0;
			else {
				int id = mp[pr];
				if (buk[id] < 2) ok = 0;
				V[i][j] = id;
			}
		}
		if (!ok) del[i] = 1;
	}
//	for (int i = 1; i <= N; ++i) {
//		if (del[i]) { puts("x"); continue; }
//		for (int x : V[i]) printf("%d, ", x);
//		puts("");
//	}
	for (int i = 1; i <= N; ++i) if (!del[i]) {
		int sz = (int)V[i].size();
		if (sz == 1) V2[V[i][0]].push_back(i);
	}
	// ===================================================
	int tot = 0;
	for (int i = 1; i <= N; ++i) if (!del[i]) ++tot;
	if (K > tot) return puts("0"), 0;
	int type = 0;
	for (int i = 1; i <= cnt; ++i) if (buk[i] > 2) type = i;
	if (type || (K % 2 == 0)) {
		if (!type) {
			for (int i = 1; i <= cnt; ++i) if (buk[i] >= 2) type = i;
		}
		int num = K & 1 ? 3 : 2;
		for (int i = 0; i < num; ++i) printf("%lld ", A[V2[type][i]]), usd[V2[type][i]] = 1;
		K -= num;
		for (int j = 1; j <= cnt && K; ++j) if (buk[j] >= 2 && j != type) {
			for (int i = 0; i < 2; ++i) printf("%lld ", A[V2[j][i]]), usd[V2[j][i]] = 1;
			K -= 2;
		}
		for (int i = 1; i <= N && K; ++i) if (!del[i] && !usd[i])
			printf("%lld ", A[i]), --K;
		puts("");
	} else {
		int id = 0, mnsz = 9999999;
		for (int i = 1; i <= N; ++i) if (!del[i]) {
			int sz = (int)V[i].size();
			if (sz >= 2) {
				if (sz < mnsz)
					mnsz = sz,
					id = i;
			}
		}
		if (K < 2 * mnsz + 1) return puts("0"), 0;
		printf("%lld ", A[id]), usd[id] = 1;
		for (int j : V[id])
			for (int i = 0; i < 2; ++i) printf("%lld ", A[V2[j][i]]), usd[V2[j][i]] = 1;
		K -= 2 * mnsz + 1;
		for (int j : V[id]) usdp[j] = 1;
		for (int j = 1; j <= cnt && K; ++j) if (buk[j] >= 2 && !usdp[j]) {
			for (int i = 0; i < 2; ++i) printf("%lld ", A[V2[j][i]]), usd[V2[j][i]] = 1;
			K -= 2;
		}
		for (int i = 1; i <= N && K; ++i) if (!del[i] && !usd[i])
			printf("%lld ", A[i]), --K;
	}
	return 0;
}

/*
5 3
2 4 5 25 6

5 5
9999973 99999460000729 9999991 99999820000081 99999640000243

*/