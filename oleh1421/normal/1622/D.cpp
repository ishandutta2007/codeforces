#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=5010;
const ll mod=998244353;
int a[N];
ll C[N][N];
void solve(){
    int n;cin>>n;
    int k;cin>>k;
    int tot=0;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=(c-'0');
        tot+=a[i];
    }
    if (tot<k){
        cout<<1<<endl;
        return;
    }
    C[0][0]=1;
    for (int i=1;i<=n;i++){
        C[i][0]=1;
        for (int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
    ll res=1;
    for (int i=1;i<=n;i++){
        int j=i;
        int cnt=a[i];
        while (j+1<=n && cnt+a[j+1]<=k) cnt+=a[++j];
        if (cnt-(a[i]+1)%2>=0) res+=C[j-i][cnt-(a[i]+1)%2];
        res%=mod;
    }
    cout<<res<<endl;

}
int32_t main()
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