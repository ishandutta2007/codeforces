#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())

const int maxn = 1e5 + 85 - 69;
set<pii> s[maxn];
vector<int> adj[maxn];
int Last, root[maxn], n, c[maxn];
LL sum[maxn], Max[maxn], ans[maxn];

bool cmp(int i, int j){
	return sz(s[i]) > sz(s[j]);
}

void Insert(int id, pii val){
	auto it = s[id].lower_bound(MP(val.L, 0));
	pii ins;
	if(it == s[id].end() or it->L != val.L)
		ins = val;
	else{
		ins = *it;
		s[id].erase(it);
		ins.R += val.R;
	}
	s[id].insert(ins);
	if(ins.R > Max[id]){
		Max[id] = ins.R;
		sum[id] = ins.L;
	}
	else if(ins.R == Max[id])
		sum[id] += ins.L;
	return;
}

void dfs(int v, int p = -1){
	if((p == -1 and sz(adj[v]) == 0) or (p != -1 and sz(adj[v]) == 1)){
		root[v] = Last++;
		s[root[v]].insert(MP(c[v], 1));
		sum[root[v]] = c[v];
		Max[root[v]] = 1;
		ans[v] = c[v];
		return;
	}
	vector<int> vec;
	for(auto u : adj[v])
		if(u != p){
			dfs(u, v);
			vec.PB(root[u]);
		}
	sort(vec.begin(), vec.end(), cmp);
	root[v] = vec[0];
	for(int i = 1; i < sz(vec); i++)
		for(auto p : s[vec[i]])
			Insert(root[v], p);
	Insert(root[v], MP(c[v], 1));
	ans[v] = sum[root[v]];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	dfs(1);
	for(int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}