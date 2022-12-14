#include"bits/stdc++.h"

using namespace std;

int n;
int m;

#define MAX 100002

vector<int> v[MAX];
vector<int> r[MAX];

vector<int> node;
bool vis[MAX];

int belong[MAX];

vector<vector<int> > con;

void dfs2(int b,int d) {
	vis[b] = false;
	con.back().push_back(b);
	belong[b] = d;
	for (int go : r[b]) {
		if (vis[go]==false)continue;
		dfs2(go,d);
	}
}
void dfs(int b) {
	if (vis[b])return;;
	vis[b] = true;
	for (int go : v[b]) {
		if(vis[go]==false)dfs(go);
	}
	node.push_back(b);
}

bool can[MAX][52];

queue<pair<int, int> > q;
int d;

vector<int> g[MAX];

vector<pair<int, int> > ed;

queue<int> w;


bool vs[MAX];

void calc(int node) {
	if (vs[node])return;
	vs[node] = true;
	for (int go : g[node]) {
		calc(go);
	}
}

int par[MAX];

char sc[100002][52];

int tmp[MAX];
int mini[MAX];

int dp[MAX][52];

vector<pair<int, int> > lis[MAX];

int main() {
	cin >> n >> m>>d;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		ed.push_back(make_pair(a, b));
		v[a].push_back(b);
		r[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		scanf("%s", sc[i]);
	}
	for (int i = 0; i < n; i++) {
		if (vis[i])continue;
		dfs(i);
	}
	reverse(node.begin(), node.end());
	int od = 0;
	for (int b : node) {
		if (vis[b] == false)continue;
		con.push_back(vector<int>());
		dfs2(b,od);
		od++;
	}
	for (int i = 0; i < od; i++) {
		can[con[i][0]][0] = true;
		q.push(make_pair(con[i][0], 0));
		while (!q.empty()) {
			int a = q.front().first;
			int b = q.front().second;
			q.pop();
			for (int go : v[a]) {
				if (belong[a] == belong[go]) {
					int bb = b + 1;
					bb %= d;
					if (can[go][bb] == false) {
						can[go][bb] = true;
						q.push(make_pair(go, bb));
					}
				}
			}
		}
	}
	for (auto el : ed) {
		if (belong[el.first] != belong[el.second]) {
			g[belong[el.first]].push_back(belong[el.second]);
			lis[belong[el.first]].push_back(el);
		}
	}
	for (int i = 0; i < od; i++) {
		sort(g[i].begin(), g[i].end());
		g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
	}
	calc(belong[0]);
	for (int i = 0; i < od; i++) {
		if (vs[i]) {
			for (int z : g[i]) {
				par[z]++;
			}
		}
	}
	w.push(belong[0]);
	int ans = 0;
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	while (!w.empty()) {
		int b = w.front();
		w.pop();
		int ava = d;
		assert(can[con[b][0]][0]);
		for (int j = 1; j < d; j++) {
			if (can[con[b][0]][j]) {
				ava = j;
				break;
			}
		}
		for (int j = 0; j < d; j++) {
			if (j%ava == 0) {
				if (can[con[b][0]][j] == false)exit(1);
			}
			else {
				if (can[con[b][0]][j])exit(1);
			}
		}
		for (int k : con[b]) {
			mini[k] = INT_MAX;
			for (int j = 0; j < d; j++) {
				if (can[k][j]) {
					mini[k] = j;
					break;
				}
			}
		}
		for (int j = 0; j < ava; j++) {
			tmp[j] = 0;
			for (int k : con[b]) {
				int tim = (j + mini[k]) % ava;
				while (tim < d) {
					if (sc[k][tim] == '1') {
						tmp[j]++;
						break;
					}
					tim += ava;
				}
			}
			int mm = -1;
			for (int k : con[b]) {
				int tim = (j + mini[k]) % ava;
				while (tim < d) {
					mm = max(mm, dp[k][tim]);
					tim += ava;
				}
			}
			if (mm == -1) {
				tmp[j] = -1;
			}
			else {
				tmp[j] += mm;
			}
			ans = max(ans, tmp[j]);
		}
		for (int z : g[b]) {
			par[z]--;
			if (par[z] == 0) {
				w.push(z);
			}
		}
		for (auto u:lis[b]) {
			int from = u.first;
			int z = u.second;
			for (int j = 0; j < ava; j++) {
				for (int tim = j; tim < d; tim += ava) {
					int cur = mini[from] + tim;
					cur %= d;
					int go = cur + 1;
					go %= d;
					dp[z][go] = max(dp[z][go], tmp[j]);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}