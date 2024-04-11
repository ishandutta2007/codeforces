#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
///use char if you want a naive algorithm to pass
#include <bits/stdc++.h>
//#include <vector>
#define endl '\n'
typedef long long ll;
using namespace std;
const int N=200010;
void solve(){
    int n,a,b;cin>>n>>a>>b;
    string s="";
    for (int i=0;i<a;i++){
        if (i<b) s+=char('a'+i);
        else s+=char('a');
    }
    for (int i=a;i<n;i++){
        s+=s[i-a];
    }
    cout<<s<<endl;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}