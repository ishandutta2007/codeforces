#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
vector<int> T[N];
ll ai[N];

ll to[N];

ll maxp[N];

void dfs1(int u, int par){
	to[u] = ai[u];
	maxp[u] = ai[u];
	ll mx1 =0, mx2 = 0;
	for(auto x : T[u]){
		if(x == par)
			continue;
		dfs1(x, u);
		to[u] = max(to[u], to[x] + ai[u]);
		if(to[x] >= mx1){
			mx2 = mx1;
			mx1 = to[x];
		}
		else if(to[x] >= mx2){
			mx2 = to[x];
		}
		maxp[u] = max(maxp[u], maxp[x]);
	}
	maxp[u] = max(maxp[u], ai[u] + mx1 + mx2);
}

ll answ = 0;

void dfs2(int u, int par, ll maxpath, ll maxr){
	answ = max(answ, maxpath + maxp[u]);
	multiset<ll> tou, inu;
	for(auto x : T[u]){
		if(x == par)
			continue;
		tou.insert(to[x]);
		inu.insert(maxp[x]);
	}
	
	tou.insert(maxr);
	inu.insert(maxpath);
	
	ll m1, m2;
	int cnt = 0;
	
	ll pat;
	
	ll maxi;
	
	ll nxpat;
	
	for(auto x : T[u]){
		if(x == par)
			continue;
		tou.erase(tou.find(to[x]));
		inu.erase(inu.find(maxp[x]));
		
		m1 = 0, m2 = 0;
	
		cnt = 2;
		
		auto it = tou.end();
		while(it != tou.begin() && cnt > 0){
			it -- ;
			cnt -- ;
			if(cnt == 1)
				m1 = *it;
			else
				m2 = *it;
		}
		
		maxi = 0;
		
		if(!inu.empty()){
			it = inu.end();
			-- it;
			maxi = max(maxi, *it);
		}
		pat = m1 + ai[u];
		nxpat = maxpath;
		nxpat = max(nxpat, m1 + m2 + ai[u]);
		nxpat = max(nxpat, maxi);
		dfs2(x, u, nxpat, pat);
		
		tou.insert(to[x]);
		inu.insert(maxp[x]);
	}
}

int main(){
	fastIO;
	int n;
	cin >> n;
	for(int i = 1; i <= n ; i ++ )
		cin >> ai[i];
	int u, v;
	for(int i = 1; i < n; i ++ ){
		cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	dfs1(1, -1);
	dfs2(1, -1, 0, 0);
	cout << answ << "\n";
	return 0;
}