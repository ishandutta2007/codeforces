#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
#define endl '\n'
const int N=500010;
const int T_SZ=3000010;
const ll mod=1000000007;

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    string ans="";
    for (int i=0;i<n;i++) ans+=".";

    for (int i=0;i<n;i++){
        if (s[i]=='U') ans[i]='D';
        else if (s[i]=='D') ans[i]='U';
    }
    int cnt=0;
    for (int i=0;i<n;i++){
        if (ans[i]=='.'){
            if (cnt%2) ans[i]='R';
            else ans[i]='L';
            cnt++;
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

//0 2
//-1 3
//1 3
//0 4
/*
8
1 104
220 909
380 378
521 641
765 184
802 969
897 729
992 887

C - centroid

5
0 0 -1 -1 1
*/