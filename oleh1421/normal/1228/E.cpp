//#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int long long
using namespace std;
ll f[2001];
ll rf[2001];
const long long mod=1000000007ll;
ll binpow(ll a,ll b){
   if (b==0) return 1ll;
   if (b%2ll) return (a*binpow(a,b-1ll))%mod;
   else return binpow((a*a)%mod,b/2ll);
}
ll C(int n,int k){
   if (k>n) return 0;
   return ((rf[k]*rf[n-k])%mod*f[n])%mod;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin>>n>>k;
    f[0]=1ll;
    for (ll i=1;i<=n;i++) f[i]=(f[i-1]*i)%mod;
    rf[0]=1ll;
    for (ll i=1;i<=n;i++) rf[i]=binpow(f[i],mod-2ll);
    ll res=0ll;
    for (int j=0;j<=n;j++){
        for (int t=0;t<=n;t++){
           /*if ((j+t)%2==0){
                    res+=(((C(n,t))%mod*C(n,j))%mod*binpow(k,n*n))%mod;
                    res%=mod;
                    cout<<res<<endl;

            } else {
                    res+=mod-(((C(n,t))%mod*C(n,j))%mod*binpow(k,n*n))%mod;
                    res%=mod;
            }*/
            ll cur=0ll;
            if ((j+t)%2==0){
                cur+=binpow(k,n*n-n*t-n*j+t*j)*binpow(k-1ll,n*t+n*j-t*j);//((C(n*n-n*t-n*j+t*j,i))%mod*binpow(k-1ll,n*n-i))%mod;
                cur%=mod;
            } else {
                cur+=mod-binpow(k,n*n-n*t-n*j+t*j)*binpow(k-1ll,n*t+n*j-t*j);
                cur%=mod;
            }
            /*for (int i=0;i<=(n-j)*(n-t);i++){
                if ((j+t)%2==0){
                    cur+=((C(n*n-n*t-n*j+t*j,i))%mod*binpow(k-1ll,n*n-i))%mod;
                    cur%=mod;
                } else {
                    cur+=mod-((C(n*n-n*t-n*j+t*j,i))%mod*binpow(k-1ll,n*n-i))%mod;
                    cur%=mod;
                }
            }*/
            res+=((cur*C(n,t))%mod*C(n,j))%mod;
            res%=mod;
        }
    }
    cout<<res;


    return 0;
}
/*
8
0
2 0
0 4 0 1
0 0 0 0 0 5 0 0

*/