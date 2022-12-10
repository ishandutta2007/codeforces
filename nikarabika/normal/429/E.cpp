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

const int maxn = 4e5 + 85 - 69;
bool mark[maxn],
	 emark[maxn],
	 ans[maxn];
int frm[maxn],
	too[maxn],
	n;
set<pair<pii, int> > s;
vector<int> adj[maxn],
	tour,
	all;

int idof(int x){
	return lower_bound(all(all), x) - all.begin();
}

void dfs(int u){
	mark[u] = true;
	while(sz(adj[u])){
		int e = adj[u].back();
		adj[u].pop_back();
		if(emark[e]) continue;
		emark[e] = true;
		dfs(frm[e] + too[e] - u);
	}
	tour.PB(u);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> frm[i] >> too[i], too[i]++;
		all.PB(frm[i]);
		all.PB(too[i]);
	}
	sort(all(all));
	for(int i = 0; i < n; i++){
		frm[i] = idof(frm[i]);
		too[i] = idof(too[i]);
		s.insert(MP(MP(frm[i], too[i]), i));
		adj[frm[i]].PB(i);
		adj[too[i]].PB(i);
	}
	int lst = -1, oecnt = 0;
	for(int i = 0; i < sz(all); i++){
		if(sz(adj[i]) & 1){
			if(lst == -1)
				lst = i;
			else{
				int id = n + oecnt;
				frm[id] = lst, too[id] = i;
				adj[lst].PB(id);
				adj[i].PB(id);
				s.insert(MP(MP(frm[id], too[id]), id));
				oecnt++, lst = -1;
			}
		}
	}
	for(int ii = 0; ii < sz(all); ii++) if(!mark[ii]){
		tour.clear();
		dfs(ii);
		for(int i = 0; i + 1 < sz(tour); i++){
			int u = tour[i],
				v = tour[i + 1];
			auto it = s.lower_bound(MP(MP(min(v, u), max(v, u)), -1));
			ans[it->R] = u < v;
			s.erase(it);
		}
	}
	for(int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}