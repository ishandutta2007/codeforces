#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'
using namespace std;
const int N=5000010;
int n,q;
ll mod;
ll F[N];
ll val[N];
int CNT=0;
void add(int pos,ll x){
    CNT-=(val[pos]>0);
    val[pos]+=mod+x;
    val[pos]%=mod;
    CNT+=(val[pos]>0);
}
ll A[N],B[N];
void solve(){
    cin>>n>>q;
    cin>>mod;
    F[0]=1;
    F[1]=1;
    for (int i=2;i<=n;i++){
        F[i]=(F[i-1]+F[i-2])%mod;
    }
    for (int i=1;i<=n;i++) cin>>A[i];
    val[1]+=A[1];
    val[1]%=mod;
    for (int i=2;i<=n;i++){
        val[i]+=A[i]-A[i-1]-A[i-2];
        val[i]+=mod*2ll;
        val[i]%=mod;
    }

    for (int i=1;i<=n;i++) cin>>B[i];
    val[1]+=mod-B[1];
    val[1]%=mod;
    for (int i=2;i<=n;i++){
        val[i]-=B[i]-B[i-1]-B[i-2];
        val[i]+=mod*2ll;
        val[i]%=mod;
    }
    CNT=0;
    for (int i=1;i<=n;i++) CNT+=(val[i]>0);
//    for (int i=1;i<=n;i++) cout<<i<<" "<<val[i]<<endl;
    for (int i=1;i<=q;i++){
        char c;cin>>c;
        int l,r;cin>>l>>r;
        ll x=(int)(c=='A')-(int)(c=='B');
        add(l,x);
        if (r<n){
            add(r+1,-x*F[r-l+1]);
        }
        if (r+1<n){
            add(r+2,-x*F[r-l]);
        }
        if (CNT) cout<<"NO\n";
        else cout<<"YES\n";
    }





}
int32_t  main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}

/**

**/