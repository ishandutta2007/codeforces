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
const ll mod=1000000007;
char s[N];
void solve(){
    int n;cin>>n;
    char c;cin>>c;
    for (int i=1;i<=n;i++) cin>>s[i];
    for (int i=1;i<=n;i++){
        bool ok=true;
        for (int j=i;j<=n;j+=i){
            ok&=(s[j]==c);
        }
        if (ok){
            if (i==1){
                cout<<0<<endl;
                return;
            }
            cout<<1<<endl;
            cout<<i<<endl;
            return;
        }
    }
    cout<<2<<endl;
    cout<<n-1<<" "<<n<<endl;

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