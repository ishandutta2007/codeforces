#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long 
#define endl '\n'
#define mp make_pair
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
const ll N=1e3+10,mod=1e9+7;
char a[N][N];
ll dp[N][2];
ll b[N];
int main(){
	ios:: sync_with_stdio(false);
	ll n,m,x,y;
	cin >> n >> m >> x >> y;
    rep (i,0,n){
        rep(j,0,m){
            cin >> a[i][j];
        }
    }
    rep(i,0,m){
        rep(j,0,n){
            if (a[j][i] == '#') b[i+1]++;
        }
    }
    ll s1 = 0,s2 = 0;
    rep(i,1,x+1){
    	s1+=b[i];
    	s2+= n-b[i];
    	dp[i][0] = n*m;
    	dp[i][1] = n*m;
	}
	dp[x][1] = s2;
	dp[x][0] = s1;
	dp [0][0] = 0;
	dp[0][1] = 0;
	rep(i,x+1,m+1){
		repr (j,i,i-x+1){
			dp[i][0] += b[j];
			dp[i][1] += n-b[j];
		}
		s1 = n*m+2;
		s2 = n*m+2;
		ll sum0=0,sum1=0;
		repr (j,i-x,max(i-i,i-y)){
			s1 = min(s1,dp[j][0]+sum1);
			s2 = min(s2,dp[j][1]+sum0);
			sum0+=b[j];
			sum1+=n-b[j];
		}
		if (s2 != n*m+2) dp[i][0] += s2;
		else dp[i][0] = b[i] + dp[i-x][1];
		if (s1 != n*m+2) dp[i][1] += s1;
		else dp[i][1] = n-b[i] + dp[i-x][0];

//		cout << dp[i][0] << "   " << dp[i][1] << endl;
	}
	cout << min(dp[m][0],dp[m][1]);
}