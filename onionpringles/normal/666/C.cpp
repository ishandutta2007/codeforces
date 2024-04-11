#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#define mul(a,b) (long long)(a)*(b)%mod
using namespace std;

const int N = 100010;
const int mod = 1000000007;


char buf[N + 2];

vector<pair<int, int> > Q[N];
int ans[N];

int p25[N];
int fact[N];
int inv[N];
int invfact[N];

int binom(int n, int r) {
	return mul(fact[n], mul(invfact[r], invfact[n - r]));
}

vector<int> gen(int s) {
	vector<int> ret(N);
	for (int l = s; l < N; l++) {
		int haha = mul(26, ret[l - 1]);
		haha += mul(binom(l - 1, s - 1), p25[l - s]);
		if (haha >= mod) haha -= mod;
		ret[l] = haha;
	}
	return ret;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fact[0] = 1; inv[1] = 1;
	for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
	for (int i = 2; i < N; i++) inv[i] = mul(mod - mod / i, inv[mod%i]);
	invfact[0] = 1;
	for (int i = 1; i < N; i++) invfact[i] = mul(inv[i], invfact[i - 1]);
	p25[0] = 1;
	for (int i = 1; i < N; i++) {
		p25[i] = mul(25, p25[i - 1]);
	}
	int m; scanf("%d", &m);
	scanf("%s", buf);
	int cur = strlen(buf);
	int q2 = 0;
	for (int i = 0; i < m; i++) {
		int tp; scanf("%d", &tp);
		if (tp == 1) {
			scanf("%s", buf);
			cur = strlen(buf);
		}
		else {
			int l; scanf("%d", &l);
			Q[cur].emplace_back(l, q2++);
		}
	}
	//for (int i = 0; i < N; i++) if (!Q[i].empty()) sort(Q[i].begin(), Q[i].end());
	for (int i = 0; i < N; i++) {
		if (Q[i].empty()) continue;
		auto V = gen(i);
		for (auto &x : Q[i]) {
			ans[x.second] = V[x.first];
		}
	}
	for (int i = 0; i < q2; i++) printf("%d\n", ans[i]);
	return 0;
}