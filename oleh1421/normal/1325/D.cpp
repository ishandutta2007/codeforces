//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC opitmize ("trapv")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
ll ans[1010];
int32_t main()
{
//
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a,b;cin>>a>>b;
    if (a>b || (a%2ll)!=(b%2ll)){
        cout<<-1;
        return 0;
    }
    ll cn=0;
    int n=0;
    for (ll i=62;i>=0;i--){

        ll xr=((a>>i)&1ll);
        cn*=2;
        cn+=((b>>i)&1ll);
//        cout<<i<<" "<<cn<<" "<<xr<<" "<<(a&((1<<i)-1))<<" "<<(b&((1<<i)-1))<<" "<<endl;
        if (xr%2ll!=cn%2ll){
            if (cn==0) exit(1);
            for (int j=1;j<cn;j++) ans[j]^=(1ll<<i);
            n=max(n,(int)cn-1);
            cn=1;
        } else {
            if (cn>1 && i>0 && (a&((1ll<<i)-1))>(b&((1ll<<i)-1))){
                for (int j=1;j<=cn-2;j++) ans[j]^=(1ll<<i);
                n=max(n,(int)cn-2);
                cn=2;
//                ll xr=a;
//                for (int j=1;j<=n;j++) xr^=ans[j];

            } else {
                for (int j=1;j<=cn;j++) ans[j]^=(1ll<<i);
                n=max(n,(int)cn);
                cn=0;

            }
        }
    }
    cout<<n<<endl;
    for (int i=1;i<=n;i++) a^=ans[i],cout<<ans[i]<<" ";
    return 0;
}