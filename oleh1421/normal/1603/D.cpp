//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
//#define int ll
#define endl '\n'
using namespace std;
mt19937_64 rnd(time(NULL));
const int N=100010;
const ll inf=10000000000000001;
ll dp[21][N];
int phi[N];
ll sum[N];
void solve(){
    int n,k;cin>>n>>k;
    if (k>20){
        cout<<n<<endl;
        return;
    }
    cout<<dp[k][n]<<endl;

}
ll f(int l,int r){
    ll res=0ll;
    for (int i=l;i<=r;i++){
        int j=(r/(r/i));
        res+=sum[r/i]*(j-i+1ll);
        i=j;
    }
    return res;
}
void rec(int j,int l,int r,int L,int R){
    if (l>r) return;
    int m=(l+r)/2;
    dp[j][m]=inf;
    ll add=f(L,m);
    int pos=0;
    for (int i=L;i<=min(m,R);i++){
        ll cur=dp[j-1][i-1]+add;
        if (cur<dp[j][m]){
            dp[j][m]=cur;
            pos=i;
        }
        add-=sum[m/i];
    }
    rec(j,l,m-1,L,pos);
    rec(j,m+1,r,pos,R);
}
int32_t  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n=100000;
    for (int i=1;i<=n;i++) phi[i]=i;
    for (int i=2;i<=n;i++){
        if (phi[i]==i){
            for (int j=i;j<=n;j+=i){
                phi[j]/=i;
                phi[j]*=i-1;
            }
        }
    }
    sum[0]=0;
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+phi[i];
    for (int i=1;i<=n;i++) dp[1][i]=f(1,i);
    for (int j=2;j<=20;j++){
        rec(j,1,n,1,n);
    }
//    for (int j=2;j<=20;j++){
//        for (int i=1;i<=n;i++){
//            dp[j][i]=inf;
//            for (int t=1;t<=i;t++){
//                dp[j][i]=min(dp[j][i],f(t,i)+dp[j-1][t-1]);
//            }
//        }
//    }
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}


/**

**/