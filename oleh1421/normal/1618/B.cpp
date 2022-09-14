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
    int n;cin>>n;
    for (int i=1;i<=n-2;i++) cin>>s[i];
    s[n-1]="aa";
    int ind=n-2;
    for (int i=2;i<=n-2;i++){
        if (s[i-1][1]!=s[i][0]){
            ind=i-1;
            break;
        }
    }
    string ans="";
    for (int i=1;i<=ind;i++) ans+=s[i][0];
    ans+=s[ind][1];
    ans+=s[ind+1][0];
    for (int i=ind+1;i<=n-2;i++) ans+=s[i][1];
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
10 30 15
12 31 14 18

10 12 14 15 18 30 31
**/