#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long 
#define endl '\n'
#define mp make_pair
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for(ll i=r; i>=l; i--)
using namespace std;
const int N=5e3+30,mod=1e9+7;
ll dp[N][N];
int main(){
	ios:: sync_with_stdio(false);
	string s,t;
	cin >> s >> t;
	rep (i,0,s.size()){
		if (s[i] == t[0]) dp[i][0] = 1;
		else dp[i][0] = 0;
		//cout << dp[i][0] << " ";
	}
	rep (i,1,t.size()){
		if (t[i] == s[0]) dp[0][i] = (dp[0][i-1]+1)%mod;
		else dp[0][i] = dp[0][i-1];
		//cout << dp[0][i] << " ";
	}
	rep (i,1,s.size()){
		rep(j,1,t.size()){
			if (i+j){
				if (s[i] != t[j]) {
					dp[i][j] = dp[i][j-1];
				}
				else{
					dp[i][j] = (dp[i][j-1] + dp[i-1][j-1]+1)%mod;
				}
			}
		}
	}
	ll ans=0;
	rep (i,0,s.size()){
		ans += (dp[i][t.size()-1]);
		ans %= mod;
//		cout << dp[i][t.size()-1] << "  ";
	}
	cout << ans;
}