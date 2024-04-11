//A Twisty Movement O(N * N) approach

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
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = 2005;
int dp[N][4];

int main(){
	fastIO;
	int n;
	cin >> n;
	int a;
	int ans = 0;
	for(int i = 1;i<=n;i++){
		cin >> a;
		dp[i][0] = dp[i-1][0];
		dp[i][1] = dp[i-1][1];
		dp[i][2] = dp[i-1][2];
		dp[i][3] = dp[i-1][3];
		if(a == 1){
			dp[i][0] = dp[i-1][0] + 1;
			dp[i][2] = max(dp[i-1][1],dp[i-1][2]) + 1;
		}
		else{
			dp[i][1] = max(dp[i][0],dp[i][1]) + 1;
			dp[i][3] = max(dp[i][2],dp[i][3]) + 1;
		}
		for(int j = 0;j<4;j++){
			ans = max(ans,dp[i][j]);
		}
	}
	cout << ans;
	return 0;	
}