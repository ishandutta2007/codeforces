#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T>using ordered_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
#define endl '\n'
const int N=400010;
const ll mod=1000000007;

void solve(){
    int n;cin>>n;
    string s;cin>>s;
    int pos=-1;
    for (int i=0;i<n;i++){
        if (s[i]=='?') continue;
        pos=i;
        break;
    }
    if (pos==-1){
        for (int i=0;i<n;i++){
            if (i%2) cout<<'B';
            else cout<<'R';
        }
        cout<<endl;
        return;
    }
    for (int i=pos-1;i>=0;i--){
        if (s[i]=='?'){
            if (s[i+1]=='B') s[i]='R';
            else s[i]='B';
        }
    }
    for (int i=pos+1;i<n;i++){
        if (s[i]=='?'){
            if (s[i-1]=='B') s[i]='R';
            else s[i]='B';
        }
    }
    cout<<s<<endl;


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
/*
ba
ca
aca
a
b
c
ac
*/