//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=2000000000000000001ll;
const ll mod=998244353;
using namespace std;
mt19937 rnd(time(NULL));
const int N=200010;
int x[N],y[N],s[N],p[N];
int dp[N];
int val[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>x[i]>>y[i]>>s[i];
    for (int i=1;i<=n;i++){
        p[i]=lower_bound(x+1,x+n+1,y[i])-x;
    }
    dp[0]=0;
    val[0]=0;
    for (int i=1;i<=n;i++){
        val[i]=(val[i-1]*2ll+(x[i]-x[i-1])*2ll+(x[p[i]-1]-y[i])-val[p[i]-1]+mod*2ll)%mod;
        if (s[i]==0){
            dp[i]=(dp[i-1]+x[i]-x[i-1])%mod;
        }  else {
            dp[i]=(dp[i-1]+val[i-1]+(x[i]-x[i-1])*2ll+(x[p[i]-1]-y[i])-val[p[i]-1]+mod*2ll)%mod;
        }
//        cout<<i<<" "<<dp[i]<<endl;
    }
    cout<<(dp[n]+1)%mod<<endl;


}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
/**
5
2 1 1
6 4 0
8 3 0
9 7 1
10 5 0

21
2000000001
**/
//5 10 5 9
/**
10 6
14 6
2 20
9 10
13 18
15 12
11 7
**/