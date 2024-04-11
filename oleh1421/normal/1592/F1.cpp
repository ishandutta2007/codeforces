//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
//#define int ll
#define endl '\n'
const int N=510;
const ll mod=998244353;
const ll inf=2000000000000000000;
int a[N][N];
int b[N][N];
void solve(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;cin>>c;
            a[i][j]=(c=='B');
        }
    }
    int cnt=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            b[i][j]=(a[i][j]^a[i][j+1]^a[i+1][j]^a[i+1][j+1]);
            cnt+=b[i][j];
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (b[i-1][j-1] && b[i-1][m] && b[n][j-1] && b[n][m]){
                cout<<cnt-1<<endl;
                return;
            }
        }
    }
    cout<<cnt<<endl;

//    cout<<ans1<<endl;
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