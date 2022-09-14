//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=1000000000000000001ll;
const ll mod=998244353;
using namespace std;
mt19937 rnd(time(NULL));
const int N=400010;
int a[N];
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2ll);
}
void solve(){
    int n;cin>>n;
//
//    dp[0][0]=1;
//    for (int i=1;i<=n;i++){
//        dp[i][0]=1;
//        for (int j=1;j<=i;j++) {
//            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
//            if (dp[i][j]==715){
//                cout<<i<<" "<<j<<endl;
//            }
////            cout<<dp[i][j]<<" ";
//        }
////        cout<<endl;
//
//    }
    string s;cin>>s;
    for (int i=1;i<=n;i++){
        a[i]=(s[i-1]-'0');
    }
    a[n+1]=0;
    int sum=0;
    int del=0;
    int cnt=0;
    int cnt1=0;
    for (int i=1;i<=n+1;i++){
        if (!a[i]){
            sum+=cnt;
            del+=cnt/2;
            cnt1+=cnt%2;
            cnt=0;
        } else cnt++;
    }
    ll res=1ll;
    int k=n-del-cnt1;
//    cout<<del<<" ";
    for (ll i=k-del+1;i<=k;i++){
        res=(res*i)%mod;
    }
    for (ll i=1;i<=del;i++){
        res=(res*binpow(i,mod-2))%mod;
    }
    cout<<res<<endl;


}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//1001000100010
/**
1
4 4
1 2
2 3
1 4
4 3
**/
//100000100010
//1000001000