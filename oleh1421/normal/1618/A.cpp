#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const int N=1000100;
string s[N];
void solve(){
    vector<int>v(7);
    for (auto &i:v) cin>>i;
    sort(v.begin(),v.end());
    cout<<v[0]<<" "<<v[1]<<" "<<v.back()-v[0]-v[1]<<endl;
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
10 30 15
12 31 14 18

10 12 14 15 18 30 31
**/