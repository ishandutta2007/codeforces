//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//#define int ll
#define endl '\n'
const int N=200010;
const ll mod=998244353;
const ll inf=2000000000000000000;

void solve(){
    string s;cin>>s;
    int sum=0;
    for (auto i:s){
        if (i=='A' || i=='C') sum++;
        else sum--;
    }
    if (sum==0) cout<<"YES\n";
    else cout<<"NO\n";

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
5
1 2 1 3 1
**/