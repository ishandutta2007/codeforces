//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;
int a[N];
void solve(){
    int n,d;cin>>n>>d;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if (a[1]+a[2]>d && a[n]>d){
        cout<<"NO\n";
    } else cout<<"YES\n";
}
int32_t main()
{
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
/*


*/