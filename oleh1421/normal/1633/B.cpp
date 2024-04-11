#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ld eps=1e-12;
const int N=200010;
const ll mod=998244353;
#define ADD(a,b) a+=b;if (a>=mod) a-=mod
#define endl '\n'
vector<pair<int,int> >g[N];

void solve(){
    string s;cin>>s;
    int cnt0=0,cnt1=0;
    for (auto i:s){
        if (i=='0') cnt0++;
        else cnt1++;
    }
    if (cnt0<cnt1) cout<<cnt0<<endl;
    else if (cnt0>cnt1) cout<<cnt1<<endl;
    else cout<<cnt0-1<<endl;

}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}