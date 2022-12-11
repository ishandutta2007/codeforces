#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

const int N = 1005;
vector<int>S[N];
vector<int>T[N];
int al[N];
int alw[N];

int w[N];
int b[N];
int col[N];

int cnt = 0;

void dfs(int u){
	col[u] = cnt;
	for(auto x : T[u])
		if(col[x] == 0)
			dfs(x);
}

int dp[N][N]; // maximum b for prefix i, weight j

int main(){
	fastIO;
	int n,m,maxw;
	cin >> n >> m >> maxw;
	for(int i = 1;i<=n;i++)
		cin >> w[i];
	for(int j = 1;j<=n;j++)
		cin >> b[j];
	int ai,bi;
	while(m--){
		cin >> ai >> bi;
		T[ai].push_back(bi);
		T[bi].push_back(ai);
	}
	for(int j=  1;j<=n;j++){
		if(col[j] != 0)
			continue;
		++cnt;
		dfs(j);
	}
	for(int i = 1;i<=n;i++){
		S[col[i]].push_back(i);
		al[col[i]] += w[i];
		alw[col[i]] += b[i];
	}
	for(int i = 1;i<=cnt;i++){
		for(int j = 0;j<=maxw;j++)
			dp[i][j] = dp[i-1][j]; // take no more
		for(int j = 0;j<=maxw;j++){
			for(auto x : S[i]){
				if(j + w[x] > maxw)
					continue;
				dp[i][j+w[x]] = max(dp[i][j+w[x]],dp[i-1][j] + b[x]);
			}
			if(j+al[i] <= maxw)
				dp[i][j+al[i]] = max(dp[i][j+al[i]],dp[i-1][j] + alw[i]);
		}
	}
	int ans = 0;
	for(int i = 0;i<=maxw;i++)
		ans = max(ans,dp[cnt][i]);
	cout << ans << "\n";
	return 0;
}