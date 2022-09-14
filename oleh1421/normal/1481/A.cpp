//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=100010;
int a[N],b[N],c[N];
set<pair<int,int> >st[N];
int x[N];
void solve(){
    int px,py;cin>>px>>py;
    string s;cin>>s;
    map<char,int>mp;
    for (auto i:s){
        mp[i]++;
    }
    if (-mp['D']<=py && py<=mp['U'] && -mp['L']<=px && px<=mp['R']){
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
    }


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
1
5 2
1 2 2 1 1
1 2 2 1 1
1 2
*/