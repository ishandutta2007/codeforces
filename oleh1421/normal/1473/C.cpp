//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;
int p[N];
void solve(){
    int n,k;cin>>n>>k;
    for (int i=1;i<=k;i++) p[i]=i;
    reverse(p+k+k-n,p+k+1);
    for (int i=1;i<=k;i++) cout<<p[i]<<" ";
    cout<<endl;
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