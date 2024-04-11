#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=450010;
int a[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int L=1000000001;
    int R=-1;
    for (int i=1;i<=n;i++){
        if (a[i]==-1){
            if (i>1 && a[i-1]!=-1) R=max(R,a[i-1]),L=min(L,a[i-1]);
            if (i<n && a[i+1]!=-1) R=max(R,a[i+1]),L=min(L,a[i+1]);
        }
    }
    if (R==-1){
        cout<<0<<" "<<1<<endl;
        return;
    }
    int k=(L+R)/2;
    int m=0;
    for (int i=1;i<=n;i++){
        if (a[i]==-1) a[i]=k;
        if (i>1) m=max(m,abs(a[i]-a[i-1]));
    }
    cout<<m<<" "<<k<<endl;
}
int32_t main()
{
//    freopen("repair.in","r",stdin);
//    freopen("repair.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;

}