#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll setv[maxn<<2];
ll orv[maxn<<2];
 
vector<ll> a;
pii id[maxn];
ll col[maxn];
vector<int> g[maxn];
int n,m;
 
ll build(int u, int l, int r){
	if (l == r){
		return orv[u] = a[l];
	}
	int mid = (l+r)/2, chl = 2 * u + 1, chr = 2 * u + 2;
	return orv[u] = build(chl, l, mid) | build(chr, mid+1, r);
}
 
int x1,x2;
ll c;
void update(int u, int l, int r){
	if (x1 <= l && x2 >= r){
		orv[u] = c;
		setv[u] = c;
		return;
	}
	if (x1 > r || x2 < l){
		return;
	}
	int mid = (l+r)/2, chl = 2 * u + 1, chr = 2 * u + 2;
	if (setv[u] != 0){
		orv[chl] = orv[chr] = setv[chl] = setv[chr] = setv[u];
		setv[u] = 0;
	}
	update(chl, l, mid);
	update(chr, mid+1, r);
	orv[u] = orv[chr] | orv[chl];
}
 
ll query(int u,int l, int r){
	if (x1 > r || x2 < l){
		return 0;
	}
	if (setv[u] != 0){
		return setv[u];
	}
	if (x1 <= l && x2 >= r){
		return orv[u];
	}
	int mid = (l+r)/2, chl = 2 * u + 1, chr = 2 * u + 2;
	return query(chl, l, mid) | query(chr, mid+1, r);
}
 
int mark[maxn];
int dfs(int u){
	mark[u] = 1;
	int tmp = -1;
	for (int e=0; e<g[u].size();e++){
		int v = g[u][e];
		if (mark[v] == 1){
			continue;
		}
		if (tmp == -1){
			tmp = dfs(v);
		}
		else{
			dfs(v);
		}
		
	}
	if (tmp == -1){
		tmp = a.size();
	}
	id[u] = mp(tmp, a.size());
	a.pb(col[u]);
	return tmp;
}
 
 
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		int c;
		cin>>c;
		col[i] = (ll)1 << (ll)(c-1);
	}
	for (int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1);
	//for (int i=1;i<=n;i++){
	//	cout << id[i].fi << "," << id[i].se << endl;
	//}
	build(0, 0, a.size()-1);
	for (int i=0;i<m;i++){
		int t,x,y;
		cin>>t;
		if (t == 1){
			cin>>x>>y;
			x1 = id[x].fi;
			x2 = id[x].se;
			c = (ll)1 << (ll)(y-1);
			update(0, 0, a.size()-1);
		}
		else{
			cin>>x;
			x1 = id[x].fi;
			x2 = id[x].se;
			ll tmp = query(0, 0, a.size()-1);
			int ans = 0;
			while (tmp > 0){
				if (tmp & 1LL){
					ans++;
				}
				tmp >>= 1LL;
			}
			cout << ans << endl;
		}
	}
}