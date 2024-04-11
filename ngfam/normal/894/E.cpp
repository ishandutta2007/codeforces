#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n, m, cnt, team;
int low[N];
int num[N];
int ans[N];
int dead[N];
stack < int > f;
vector < int > adj[N];
vector < pair < int, int > > gra[N];

void tarjan(int u){
	f.push(u);
	low[u] = num[u] = ++cnt;


	for(int v : adj[u]){
		if(dead[v]) continue;
		if(num[v]){
			low[u] = min(low[u], num[v]);
		}
		else{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
	}
	if(num[u] <= low[u]){
		int ok = (f.top() != u);
		++team;
		while(!f.empty()){
			int x = f.top();
			f.pop();
			ans[x] = team;
			dead[x] = 1;
			if(x == u) break;
		}
	}
}

int deg[N];
long long sum[N];
vector < pair < int, int > > DAG[N];
vector < int > topo;

long long dp[N];
long long preC[N];
long long sumPrec[N];
long long bowPrec[N];

long long solve(int x){
	int t = upper_bound(preC + 1, preC + 100000, 1LL * x) - preC - 1;
	return 1LL * x * (t + 1) - sumPrec[t];
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int start;

	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back(v);
		gra[u].emplace_back(v, w);
	}

	for(int i = 1; i <= 100000; ++i){
		preC[i] = preC[i - 1] + i;
	}



	for(int i = 1; i <= 100000; ++i){
		sumPrec[i] = sumPrec[i - 1] + preC[i];
	}


	for(int i = 1; i <= n; ++i){
		if(!num[i]) tarjan(i);
	}

	scanf("%d", &start);


	for(int i = 1; i <= n; ++i){
		for(auto x : gra[i]){
			if(ans[x.first] == ans[i]){
				sum[ans[i]] += solve(x.second);
			}
			else{
				++deg[ans[x.first]];
				DAG[ans[i]].emplace_back(ans[x.first], x.second);
			}
		}
	}

	stack < int > st;
	for(int i = 1; i <= team; ++i){
		if(deg[i] == 0){
			st.push(i);
		}
	}

	while(!st.empty()){
		int x = st.top();
		st.pop();

		topo.push_back(x);

		for(auto v : DAG[x]){
			--deg[v.first];
			if(deg[v.first] == 0){
				st.push(v.first);
			}
		}
	}

	start = ans[start];
	long long ret = -1e18;

	for(int i = 1; i <= team; ++i){
		dp[i] = -1e18;
	}

	dp[start] = sum[start];

	for(int x : topo){
		ret = max(ret, dp[x]);
		for(auto p : DAG[x]){
			dp[p.first] = max(dp[p.first], dp[x] + sum[p.first] + p.second);
		}
	}

	cout << ret;

	return 0;
}