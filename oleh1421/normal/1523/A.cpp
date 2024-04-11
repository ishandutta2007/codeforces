#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=500010;
int a[N];
int l[N],r[N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        char c;cin>>c;
        a[i]=(c-'0');
    }
    l[0]=-2000000001;
    for (int i=1;i<=n;i++){
        if (a[i]) l[i]=i;
        else l[i]=l[i-1];
    }
    r[n+1]=2000000001;
    for (int i=n;i>=1;i--){
        if (a[i]) r[i]=i;
        else r[i]=r[i+1];
    }
    for (int i=1;i<=n;i++){
        l[i]=i-l[i];
        r[i]=r[i]-i;
    }
    for (int i=1;i<=n;i++){
        if (a[i]) cout<<1;
        else if (l[i]!=r[i] && min(l[i],r[i])<=m) cout<<1;
        else cout<<0;
    }
    cout<<endl;
 
}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}