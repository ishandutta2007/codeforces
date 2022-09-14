#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=500010;
void solve(){
    int n,x,y;cin>>n>>x>>y;
//    i>=max(n-x-y,1)
//3+5+1-5=4
//1 2 4 5
//1 2 3 4
    int l=max(x+y+1-n,1);
//    cout<<l<<endl;
    int cn=n-l+1;
    if (max(x,y)>=l) cn--;
    cout<<n-cn<<" ";
    int r=x+y-1;
    cout<<min(r,n)<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
///4 1 3
//1 1 3
//2 2 4
//3 3 2
//4 4 1