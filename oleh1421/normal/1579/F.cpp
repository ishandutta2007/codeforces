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
const int N=1000010;
const ll mod=998244353;
const ll inf=2000000000000000000;
int a[N];
void solve(){
    ll n,d;cin>>n>>d;
    for (int i=0;i<n;i++) cin>>a[i];
    int g=__gcd(n,d);
    int ans=0;
    for (int i=0;i<g;i++){
        vector<int>v;
        for (ll j=0;j<n/g;j++){
            v.push_back(a[(i*1ll+j*d)%n]);
        }
        int A=1;
        for (int j:v) A&=j;
        if (A){
            cout<<-1<<endl;
            return;
        }
        for (ll j=0;j<n/g;j++){
            v.push_back(a[(i*1ll+j*d)%n]);
        }
        int cnt=0;
        for (int i:v){
            if (i) cnt++;
            else cnt=0;
            ans=max(ans,cnt);
        }
    }
    cout<<ans<<endl;

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