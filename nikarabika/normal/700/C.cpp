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

const int maxn = 1000 + 85 - 69,
	  maxm = 30 * 1000 + 85 - 69;
int frm[maxm],
	too[maxm];
LL wei[maxm];
vector<int> path, path2,
	adj[maxn];
int h[maxn],
	dp[maxn];
bool mark[maxn];
int n, m, eid, st, en;

int other(int e, int v){
	return frm[e] == v ? too[e] : frm[e];
}

int dn(int e){
	return h[frm[e]] > h[too[e]] ? frm[e] : too[e];
}

int up(int e){
	return h[frm[e]] < h[too[e]] ? frm[e] : too[e];
}

void find_path(int v, int sink, int ein = -1){
	mark[v] = true;
	path.PB(ein);
	bool found = false;
	for(auto e : adj[v]){
		int u = other(e, v);
		if(e != ein and !mark[u]){
			find_path(u, sink, e);
			if(mark[sink]){
				found = true;
				break;
			}
		}
	}
	if(!found and v != sink)
		path.pop_back();
	return;
}

bool find_path2(int v, int sink, int ein = -1){
	//cout << "Beginning " << v << endl;
	mark[v] = true;
	path2.PB(ein);
	bool found = false;
	for(auto e : adj[v]){
		int u = other(e, v);
		if(e != ein and e != eid){
			if(mark[u]){
				smin(dp[v], h[u]);
				continue;
			}
			h[u] = h[v] + 1;
			if(find_path2(u, sink, e))
				found = true;
			smin(dp[v], dp[u]);
		}
	}
	if(!found and v != sink) return path2.pop_back(), false;
	//cout << "Ending " << v << endl;
	return true;
}

int check(void){
	memset(mark, false, sizeof mark);
	memset(dp, 63, sizeof dp);
	memset(h, 0, sizeof h);
	path2.clear();
	find_path2(st, en);
	if(sz(path2) == 0)
		return m;
	int ret = -1;
	for(int e : path2)
		if(e != -1)
			if(dp[dn(e)] > h[up(e)] and (ret == -1 or wei[e] < wei[ret]))
				ret = e;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	path.reserve(1 << 10);
	path2.reserve(1 << 10);
	memset(dp, 63, sizeof dp);
	cin >> n >> m
		>> st >> en;
	st--, en--;
	for(int i = 0; i < m; i++){
		int fi, se, th;
		cin >> fi >> se >> th;
		fi--, se--;
		adj[fi].PB(i);
		adj[se].PB(i);
		too[i] = fi, frm[i] = se, wei[i] = th;
	}
	find_path(st, en);
	if(sz(path) == 0){
		cout << 0 << endl << 0 << endl;
		return 0;
	}
	pair<LL, pii> ans = MP(2e9 + 10, MP(-1, -1));
	for(auto e : path){
		if(e == -1)
			continue;
		eid = e;
		int id = check();
		if(~id)
			smin(ans, MP(wei[e] + wei[id], MP(e, id)));
	}
	if(ans.R.L == -1)
		cout << -1 << '\n';
	else{
		cout << ans.L << '\n';
		cout << 1 + (ans.R.R != m) << '\n';
		cout << ans.R.L + 1 << ' ';
		if(ans.R.R != m) cout << ans.R.R + 1;
		cout << '\n';
	}
	return 0;
}