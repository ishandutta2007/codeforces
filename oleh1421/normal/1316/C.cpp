#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
///#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=1000050;
int a[N];
int b[N];
void solve(){
    int n,m,p;cin>>n>>m>>p;
    for (int i=0;i<n;i++) cin>>a[i],a[i]%=p;
    for (int i=0;i<m;i++) cin>>b[i],b[i]%=p;
    int x=-1;
    for (int i=0;i<n;i++){
        if (a[i]){
            x=i;
            break;
        }
    }
    int y=-1;
    for (int i=0;i<m;i++){
        if (b[i]){
            y=i;
            break;
        }
    }
    cout<<x+y<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}