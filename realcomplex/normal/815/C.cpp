#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 5005;
const int MAX = (int)1e9 + 9;

vector<int> T[N];

int ci[N];
int di[N];
int dp[N][N][2];

void setmin(int &x, int d){
	x = min(x, d);
}

int subt[N];

void dfs(int u){
	subt[u] = 1;
	dp[u][0][0] = 0;
	dp[u][1][0] = ci[u];
	dp[u][1][1] = di[u];
	for(auto x : T[u]){
		dfs(x);
		for(int j = subt[u] ; j >= 0 ; j -- ){
			for(int z = subt[x] ; z >= 0; z -- ){
				setmin(dp[u][j + z][1], dp[u][j][1] + dp[x][z][1]);
				setmin(dp[u][j + z][1], dp[u][j][1] + dp[x][z][0]);
				setmin(dp[u][j + z][0], dp[u][j][0] + dp[x][z][0]);
			}
		}
		subt[u] += subt[x];
	}
}

int main(){
	fastIO;
	int n, b;
	cin >> n >> b;
	int p;
	for(int i = 1; i <= n; i ++ ){
		cin >> ci[i] >> di[i];
		di[i] = ci[i] - di[i];
		if(i > 1){
			cin >> p;
			T[p].push_back(i);
		}
	}
	for(int i = 0 ; i <= n; i ++ ){
		for(int j = 0 ; j <= n; j ++ ){
			for(int z = 0; z < 2; z ++ )
				dp[i][j][z] = MAX;
		}
	}
	dfs(1);
	for(int i = n; i >= 0 ; i -- ){
		if(dp[1][i][0] <= b || dp[1][i][1] <= b){
			cout << i;
			return 0;
		}
	}
	return 0;
}