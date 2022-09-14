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
const int N=2010;
const ll mod=998244353;
const ll inf=2000000000000000000;
int a[N][N],b[N][N];
void solve(){
    int n,m,k;cin>>n>>m>>k;
    for (int i=0;i<=n+1;i++){
        for (int j=0;j<=m+1;j++){
            a[i][j]=b[i][j]=0;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c;cin>>c;
            a[i][j]=(c=='*');
//            b[i][j]=0;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j]){
                int h=0;
                while (a[i-h-1][j-h-1]==1 && a[i-h-1][j+h+1]==1) h++;
//                cout<<i<<" "<<j<<" "<<h<<endl;
                if (h>=k){
                    b[i][j]=1;
                    for (int t=1;t<=h;t++){
                        b[i-t][j-t]=1;
                        b[i-t][j+t]=1;
                    }
                }
            }
        }
    }
//    for (int i=1;i<=n;i++){
//        for (int j=1;j<=m;j++){
//            cout<<b[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (a[i][j]!=b[i][j]){
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}
/**
1
4 9 2
*.*.*...*
.*.*...*.
..*.*.*..
.....*...
**/