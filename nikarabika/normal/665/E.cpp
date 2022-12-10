//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1e6 + 85 - 69,
	  maxl = 35,
	  maxsz = maxn * (maxl + 5);
int cnt[maxsz],
	adj[maxsz][2],
	sz;
LL n, k;
LL ans;

void count(LL x){
	int v = 0;
	for(int i = maxl - 1; i >= 0 and ~v; i--){
		if((k>>i)&1)
			ans += (adj[v][(x>>i)&1] != -1 ? cnt[adj[v][(x>>i)&1]] : 0);
		v = adj[v][((k>>i)&1)^((x>>i)&1)];
	}
	return;
}

void add(LL x){
	int v = 0;
	for(int i = maxl - 1; i >= 0; i--){
		int &u = adj[v][(x>>i)&1];
		if(u == -1)
			u = sz++;
		v = u;
		cnt[v]++;
	}
	return;
}

void solve(void){
	memset(adj, -1, sizeof adj);
	sz = 1;
	cin >> n >> k;
	LL val = 0;
	add(0);
	for(int i = 0; i < n; i++){
		LL x;
		cin >> x;
		val ^= x;
		count(val);
		add(val);
	}
	cout << n * (n + 1) / 2 - ans << '\n';
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}