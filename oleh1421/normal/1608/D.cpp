#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=300010;
const ll mod=998244353;
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2ll);
}
int dp[N][2][2];
int cnt[3][3];
ll f[N],rf[N];
int a[N][2];
void solve(){
    int n;cin>>n;
    ll x=0,y=0;
    for (int i=1;i<=n;i++) {
        string s;cin>>s;
        for (int j=0;j<2;j++){
            if (s[j]=='W') a[i][j]=0;
            else if (s[j]=='B') a[i][j]=1;
            else a[i][j]=2;
        }
        if (a[i][0]==2 && a[i][1]==2){
            x+=2;
            y++;
        } else if (a[i][0]==2){
            if (a[i][1]==1){
                x++;
                y++;
            } else {
                x++;
            }
        } else if (a[i][1]==2){
            if (a[i][0]==1){
                x++;
                y++;
            } else {
                x++;
            }
        } else {
            if (a[i][0]==a[i][1]){
                if (a[i][0]==0) y--;
                else y++;
            }
        }
    }
    ll res=f[x]*rf[x-y]%mod*rf[y]%mod;
    ll mult=1ll;
    for (int i=1;i<=n;i++){
        if (a[i][0]==2 && a[i][1]==2) mult*=2;
        else if (a[i][0]==2 || a[i][1]==2) mult*=1;
        else if (a[i][0]==a[i][1]) mult*=0;
        mult%=mod;
    }
    res+=mod-mult;
    bool can1=1,can2=1;
    for (int i=1;i<=n;i++){
        if (!(a[i][0]!=1 && a[i][1]!=0)) can1=false;
        if (!(a[i][0]!=0 && a[i][1]!=1)) can2=false;
    }
    res+=can1;
    res+=can2;
    cout<<res%mod<<endl;


}
int main()
{
    f[0]=1;
    for (int i=1;i<N;i++) f[i]=(f[i-1]*i)%mod;
    for (int i=0;i<N;i++) rf[i]=binpow(f[i],mod-2);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;

}
/**
BB WB W? ?W

**/