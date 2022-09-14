#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
//#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int N=5010;
int a[N];
int cnt[N];
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],cnt[i]=0;
    cnt[a[1]]++;
    cnt[a[2]]++;
    for (int i=3;i<=n;i++){
        cnt[a[i]]++;
        if (cnt[a[i]]-(a[i]==a[i-1])>=2){
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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