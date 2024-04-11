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

const int maxn = 100 * 1000 + 10;
vector<int> adj[maxn];
int cnt[maxn], vert[maxn], cmpcnt, dp[2][maxn];
bool mark[maxn];
int n, m;

void dfs(int v){
	mark[v] = true;
	cmpcnt++;
	for(auto u : adj[v])
		if(!mark[u])
			dfs(u);
	return;
}

bool islucky(int num){
	return num == 0 ? true : islucky(num / 10) and (num % 10 == 7 or num % 10 == 4);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	for(int i = 0; i < n; i++) if(!mark[i]){
		cmpcnt = 0;
		dfs(i);
		cnt[cmpcnt]++;
	}
	memset(dp, -1, sizeof dp);
	int cur = 0, pre = 1;
	dp[cur][0] = 0;
	for(int i = 1; i <= n; i++) if(cnt[i]){
		swap(pre, cur);
		//cout << i << ' ' << cnt[i] << endl;
		for(int j = 0; j < i; j++){
			deque<pii> deq;
			for(int k = j; k <= n; k += i){
				int herecnt = (k - j) / i;
				while(dp[pre][k] != -1 and sz(deq) and deq.front().L > dp[pre][k] - herecnt)
					deq.pop_front();
				if(sz(deq) and deq.back().R < k - cnt[i] * i)
					deq.pop_back();
				if(dp[pre][k] != -1) deq.push_front(MP(dp[pre][k] - herecnt, k));
				dp[cur][k] = (sz(deq) ? deq.back().L + herecnt : -1);
			}
		}
		/*for(int j = 0; j <= n; j++)
			cout << dp[cur][j] << ' ';
		cout << endl;*/
	}
	int ans = 100000 + 10;
	for(int i = 1; i < maxn; i++)
		if(islucky(i) and dp[cur][i] != -1)
			smin(ans, dp[cur][i]);
	cout << (ans == 100000 + 10 ? -1 : ans - 1) << endl;
	return 0;
}