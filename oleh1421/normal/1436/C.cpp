#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=1010;
ll C[N][N];
ll f[N];
const ll mod=1000000007ll;
void solve(){

    int n,x,pos;cin>>n>>x>>pos;
    C[0][0]=1ll;
    for (int i=1;i<=n;i++){
        C[i][0]=1;
        for (int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
        }
    }
    f[0]=1ll;
    for (ll i=1;i<=n;i++){
        f[i]=(f[i-1]*i)%mod;
    }
    int gr=0,ls=0;
    int L=0,R=n;
    while (L<R){
        int mid=(L+R)/2;
        if (pos>=mid){
            L=mid+1;
            if (pos!=mid) ls++;
        } else {
            R=mid;
            gr++;
        }
    }
    int eq=n-ls-gr-1;
    cout<<C[x-1][ls]*f[ls]%mod*C[n-x][gr]%mod*f[gr]%mod*f[eq]%mod<<endl;

//    cout<<ls<<" "<<gr<<" "<<n-ls-gr<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }

    return 0;
}