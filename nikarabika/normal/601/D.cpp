//ye trie-e ghashang mizanam ghorbatan elallah :D
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Izzz wayTn' 230u :)

typedef long long int LL;

#define PB push_back
#define sz(x) ((int)(x).size())
#define endl '\n'

const int maxn = 3e5 + 85 - 69;
int tadj[maxn][26], cnt[maxn], Last;
char ch[maxn];
vector<int> adj[maxn];
char c[maxn];
int val[maxn], root[maxn], ans[maxn];
int n;

void make_child(int v, int u){
	if(tadj[v][ch[u] - 'a'] == 0){
		tadj[v][ch[u] - 'a'] = u;
		cnt[v] += cnt[u];
		return;
	}
	for(int i = 0; i < 26; i++){
		if(tadj[u][i] != 0){
			cnt[v] -= cnt[tadj[v][ch[u] - 'a']];
			make_child(tadj[v][ch[u] - 'a'], tadj[u][i]);
			cnt[v] += cnt[tadj[v][ch[u] - 'a']];
		}
	}
	return;
}

bool cmp(int i, int j){
	return cnt[i] > cnt[j];
}

void dfs(int v, int p = 0){
	root[v] = ++Last;
	ch[root[v]] = c[v];
	ans[v] = cnt[root[v]] = 1;
	vector<int> vec;
	for(auto u : adj[v]){
		if(u != p){
			dfs(u, v);
			vec.PB(root[u]);
		}
	}
	if((p == 0 and sz(adj[v]) == 0) or (p != 0 and sz(adj[v]) == 1))
		return;
	sort(vec.begin(), vec.end(), cmp);
	for(int i = 0; i < sz(vec); i++)
		make_child(root[v], vec[i]);
	ans[v] = cnt[root[v]];
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> val[i];
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	dfs(1);
	LL Max = -1, cnt;
	for(int i = 1; i <= n; i++){
		if(ans[i] + val[i] > Max){
			Max = ans[i] + val[i];
			cnt = 0;
		}
		cnt += (ans[i] + val[i] == Max);
	}
	cout << Max << endl << cnt << endl;
	return 0;
}