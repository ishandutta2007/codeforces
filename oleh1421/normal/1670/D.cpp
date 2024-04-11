#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=(1<<19);
const ll mod=1000000007;
int a[N],b[N];
int n,pw;
int p[N];
bool L[N];
vector<int>g[N];
int V[N];
int E[N];
int col[N];
void dfs(int v,int pr){
    p[v]=pr;
    col[v]=(col[pr]^1);
    for (int to:g[v]){
        if (to==pr) continue;
        dfs(to,v);
    }
}
ll f(ll x){
    return (x*x-(x/3)*(x/3)*3-(2*(x/3)+1)*(x%3));
}
void solve(){
    ll n;cin>>n;
    ll res=0ll;
    for (int i=29;i>=0;i--){
        if (f(res+(1<<i))<n) res+=(1<<i);
    }
    cout<<res+1<<endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}

/**
3 3
30 10 40
20 50 60
60 60 50

1001110110

1
5
1 2 4 2 1
4 2 2 1 1
  ,        .
**/