#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))

const int N = (int)1e5 + 12345;
vector<int>T[N];
int p[N];
int dp[N];
int in[N];
bool vis[N];

void dfs(int u){
	vis[u] = true;
	int pr = p[u];
	for(auto x : T[u]){
		in[x]--;
		dp[x] = max(dp[x],dp[u] + (p[x] == 1 and pr == 0));
		if(in[x] == 0)
			dfs(x);
	}
}

int main(){
	fastIO;
	int n,m;
	cin >> n >> m;
	for(int i = 0;i<n;i++){
		cin >> p[i];
		dp[i] = p[i];
	}
	
	int a,b;
	for(int i = 0;i<m;i++){
		cin >> b >> a;
		T[a].push_back(b);
		in[b]++;
	}
	for(int i = 0;i<n;i++){
		if(vis[i] == false){
			if(in[i] == 0){
				dfs(i);
			}
		}
	}
	int ans = 0;
	for(int j = 0;j<n;j++)ans = max(ans,dp[j]);
	cout << ans << "\n";
	return 0;	
}