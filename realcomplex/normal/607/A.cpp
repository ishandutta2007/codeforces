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

const int maxn = 1234567;
int dp[maxn];
int len[maxn];

int main(){
	fastIO;
	int n;
	cin >> n;
	int a;
	for(int i = 0;i<n;i++){
		cin >> a;
		cin >> len[a];
		dp[a] = 1;
	}
	int ans = 1;
	for(int i = 1;i<maxn;i++){
		if(len[i] == 0)
			dp[i] = dp[i-1];
		else if(i-len[i] >= 1)
			dp[i] = max(dp[i-len[i]-1]+1,dp[i]);
		ans = max(ans,dp[i]);
	}
	cout << n - ans << "\n";
	return 0;
}