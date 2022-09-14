#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
//#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
void solve(){
    string s;cin>>s;
    int maxx=0;
    int cnt=0;
    for (auto i:s){
        if (i=='R') maxx=max(maxx,cnt),cnt=0;
        else cnt++;
    }
    maxx=max(maxx,cnt);
    cout<<maxx+1<<endl;
}
int main()
{
//    freopen("three.in","r",stdin);
//    freopen("three.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}