#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld eps=1e-12;
const int N=1010;
const ll mod=998244353;
#define ADD(a,b) a+=b;if (a>=mod) a-=mod
#define endl '\n'
int b[N],c[N];
int dp[N];
int ans[N*50];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++) cin>>c[i];
    int sum=0;
    for (int i=1;i<=n;i++) sum+=dp[b[i]];
    sum=min(sum,k);
    for (int i=0;i<=sum;i++) ans[i]=0;
    for (int i=1;i<=n;i++){
        for (int j=sum;j>=dp[b[i]];j--){
            ans[j]=max(ans[j],ans[j-dp[b[i]]]+c[i]);
        }

    }
    cout<<ans[sum]<<endl;


}
int main() {
    for (int i=1;i<N;i++) dp[i]=i-1;
    int mx=0;
    for (int i=1;i<N;i++){
        for (int x=1;x<=i;x++){
            if (i+i/x<N) dp[i+i/x]=min(dp[i+i/x],dp[i]+1);
        }
        mx=max(mx,dp[i]);
    }
//    cout<<mx<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}