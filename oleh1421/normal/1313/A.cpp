#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=200010;
void solve(){
    int a,b,c;cin>>a>>b>>c;
    vector<int>v;
    for (int i=1;i<8;i++){
        v.push_back(i);
    }
    int n=v.size();
    int res=0;
    for (int i=0;i<(1<<n);i++){
        int ca,cb,cc;
        ca=cb=cc=0;
        for (int j=0;j<n;j++){
            if (i&(1<<j)){
                if (v[j]&1) ca++;
                if (v[j]&2) cb++;
                if (v[j]&4) cc++;
            }
        }
        if (ca<=a && cb<=b && cc<=c) res=max(res,__builtin_popcount(i));
    }
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    while (n--){
        solve();
    }
    return 0;
}