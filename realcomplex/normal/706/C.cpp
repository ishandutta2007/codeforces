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

int main(){
	fastIO;
	int n;
	cin >> n;
	ll f[n];
	ll dp[n][2];
	string org[n],rev[n];
	for(int i = 0;i<n;i++){
		cin >> f[i];
		dp[i][0] = (ll)1e18;
		dp[i][1] = (ll)1e18;
	}
	string a;
	for(int i = 0;i<n;i++){
		cin >> a;
		org[i] = a;
		reverse(a.begin(),a.end());
		rev[i] = a;
	}
	dp[0][0] = 0;
	dp[0][1] = f[0];
	for(int i = 1;i<n;i++){
		if(org[i] >= org[i-1] and dp[i-1][0] != (ll)1e18)
			dp[i][0] = min(dp[i][0],dp[i-1][0]);
		if(org[i] >= rev[i-1] and dp[i-1][1] != (ll)1e18)
			dp[i][0] = min(dp[i][0],dp[i-1][1]);
		if(rev[i] >= org[i-1] and dp[i-1][0] != (ll)1e18)
			dp[i][1] = min(dp[i][1],dp[i-1][0] + f[i]);
		if(rev[i] >= rev[i-1] and dp[i-1][1] != (ll)1e18)
			dp[i][1] = min(dp[i][1],dp[i-1][1] + f[i]);
	}
	if(dp[n-1][0] == (ll)1e18 and dp[n-1][1] == (ll)1e18){
		cout << "-1\n";
	}
	else{
		cout << min(dp[n-1][0],dp[n-1][1]) << "\n";
	}
	return 0;
}