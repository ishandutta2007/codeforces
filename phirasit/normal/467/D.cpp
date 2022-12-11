#include <iostream>
#include <map>
#include <stack>
#include <vector>

#define N 200010
#define A first
#define B second
#define MP make_pair

using namespace std;

typedef pair<int, int> pii;

vector<int> adj[N], Inv[N];
vector<int> adj_scc[N];

map<string ,int> pos;
pii cntr[N];
string in[N];
int n, m;

int pass[N], id[N], cnt;
stack<int> topo;

pii dp[N];

string lower(string str) {
	for(int i = 0;str[i];i++) {
		if('A' <= str[i] && str[i] <= 'Z') {
			str[i] = str[i] - 'A' + 'a';
		}
	}
	return str;
}
int cnt_r(string str) {
	int ans = 0;
	for(int i = 0;str[i];i++) {
		ans += str[i] == 'r';
	}
	return ans;
}
void topoDFS(int u) {
	if(pass[u]) {
		return;
	}
	pass[u] = 1;
	for(int i = 0;i < adj[u].size();i++) {
		topoDFS(adj[u][i]);
	}
	topo.push(u);
}
void InvDFS(int u) {
	if(pass[u]) {
		return;
	}
	pass[u] = 1;
	id[u] = cnt;
	if(cntr[u] < dp[cnt]) {
		dp[cnt] = cntr[u];
	}
	for(int i = 0;i < Inv[u].size();i++) {
		InvDFS(Inv[u][i]);
	}
}
void dpDFS(int u) {
	if(pass[u]) {
		return;
	}
	for(int i = 0;i < adj_scc[u].size();i++) {
		int v = adj_scc[u][i];
		dpDFS(v);
		if(dp[v] < dp[u]) {
			dp[u] = dp[v];
		}
	}
}
int main() {
	cin >> n;
	for(int i = 0;i < n;i++) {
		cin >> in[i];
		in[i] = lower(in[i]);
		if(!pos[in[i]]) {
			pos[in[i]] = pos.size();
			cntr[pos[in[i]]] = MP(cnt_r(in[i]), in[i].length());
		}
	}
	cin >> m;
	for(int i = 0;i < m;i++) {
		string a, b;
		cin >> a >> b;
		a = lower(a);
		b = lower(b);
		if(!pos[a]) {
			pos[a] = pos.size();
			cntr[pos[a]] = MP(cnt_r(a), a.length());
		}
		if(!pos[b]) {
			pos[b] = pos.size();
			cntr[pos[b]] = MP(cnt_r(b), b.length());
		}
		adj[pos[a]].push_back(pos[b]);
	}
	for(int i = 1;i <= pos.size();i++) {
		topoDFS(i);
	}
	for(int i = 1;i <= pos.size();i++) {
		for(int j = 0;j < adj[i].size();j++) {
			Inv[adj[i][j]].push_back(i);
		}
		pass[i] = 0;
	}
	cnt = 0;
	while(!topo.empty()) {
		int i = topo.top();
		topo.pop();
		if(!pass[i]) {
			cnt++;
			dp[cnt] = cntr[i];
			InvDFS(i);
		}
	}
	for(int i = 1;i <= pos.size();i++) {
		for(int j = 0;j < adj[i].size();j++) {
			int u = adj[i][j];
			if(id[i] != id[u]) {
				adj_scc[id[i]].push_back(id[u]);
			}
		}
	}
	for(int i = 1;i <= cnt;i++) {
		pass[i] = 0;
	}
	for(int i = 1;i <= cnt;i++) {
		dpDFS(i);
	}
	long long ans1 = 0, ans2 = 0;
	for(int i = 0;i < n;i++) {
		ans1 += dp[id[pos[in[i]]]].A;
		ans2 += dp[id[pos[in[i]]]].B;
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
}