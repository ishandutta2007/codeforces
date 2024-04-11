#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define uint unsigned int
using namespace std;

const int N = 1e6 + 7;

int n, p[N], siz[N];
vi e[N];

ll sum[N];
int rt = 0;
void dfs(int x, int f) {
	siz[x] = 1, sum[x] = 0;
	for(const int &v : e[x]) if(v != f)
		dfs(v, x), siz[x] += siz[v], sum[x] += sum[v];
	sum[x] += siz[x];
	int mx = n - siz[x];
	for(const int &v : e[x]) mx = max(mx, siz[v]);
	if(mx * 2 <= n) 
		rt = x;
}

bitset < N > bs;
int cnt[N];

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 2, n) 
		cin >> p[i], e[p[i]].emplace_back(i), e[i].emplace_back(p[i]);
	dfs(1, 0);
	dfs(rt, 0); 
	for(const int&v : e[rt]) 
		cnt[siz[v]] += 1;
	bs.set(0);
	L(i, 1, n) if(cnt[i]) {
		int k = cnt[i];
		for(int u = 1; u <= cnt[i]; u <<= 1) 
			bs |= bs << (u * i), cnt[i] -= u;
		bs |= bs << (cnt[i] * i);
	}
	ll ns = 0;
	L(i, 0, n - 1) if(bs[i]) 
		ns = max(ns, (ll) i * (n - i - 1));
	cout << ns + sum[rt] << '\n';
	return 0; 
}