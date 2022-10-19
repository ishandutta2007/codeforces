#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define lb lower_bound

using namespace std;

typedef long long ll;
const int N = 5e5 + 10;

int n , m , ff[N] , fg[N] , df[N] , dg[N] , tf[N] , tg[N] , sf[N] , sg[N];

int find(int *fa, int x) {return fa[x] == x ? x : find(fa , fa[x]);}
void merge(int *fa, int *dep, int *siz, int *tim, int x, int y, int k) {
	x = find(fa , x) , y = find(fa , y);
	if(dep[x] > dep[y]) swap(x , y);
	int tmp = dep[x] == dep[y]; siz[y] += siz[x];
	fa[x] = y , dep[y] += tmp , tim[x] = k; 
}

vector <pair<int,ll> > f[N];
int g[N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		ff[i] = fg[i] = i , sf[i] = sg[i] = 1;
	for(int i = 1; i <= n; i++)
		f[i].pb(mp(-1 , 0ll));
	for(int i = 1; i <= m; i++) {
		char op; int x , y;
		cin >> op;
		if(op == 'U') {
			cin >> x >> y;
			merge(ff , df , sf , tf , x , y , i);
		}
		else if(op == 'M') {
			cin >> x >> y;
			merge(fg , dg , sg , tg , x , y , i);
		}
		else if(op == 'A') {
			cin >> x; x = find(ff , x);
			f[x].pb(mp(i , f[x].back().second + sf[x]));
		}
		else if(op == 'Z') {
			cin >> x; x = find(fg , x);
			g[x] = i;
		}
		else if(op == 'Q') {
			cin >> x; int tag = g[x];
			for(int tx = x; fg[tx] != tx; tx = fg[tx])
				if(g[fg[tx]] > tg[tx])
					tag = max(tag , g[fg[tx]]);
			int l = lb(f[x].begin() , f[x].end() , mp(tag , -1ll)) - f[x].begin();
			ll ans = f[x].back().second - f[x][l - 1].second;
			for(; ff[x] != x; x = ff[x]) {
				l = lb(f[ff[x]].begin() , f[ff[x]].end() , mp(max(tag , tf[x]) , -1ll)) - f[ff[x]].begin();
				ans += f[ff[x]].back().second - f[ff[x]][l - 1].second;
			}
			cout << ans << endl;
		} 
	}
	return 0;
}