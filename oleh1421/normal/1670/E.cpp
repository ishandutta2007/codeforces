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

void solve(){
    cin>>pw;
    n=(1<<pw);
    for (int i=1;i<=n;i++) g[i].clear();
    for (int i=1;i<n;i++){
        cin>>a[i]>>b[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    col[0]=1;
    dfs(1,0);
    for (int i=1;i<=n;i++) V[i]=i+n-1;
    for (int i=1;i<n;i++){
        int to;
        if (a[i]==p[b[i]]) to=b[i];
        else to=a[i];
        E[i]=V[to]-n;
        if (col[to]%2) swap(V[to],E[i]);
    }
    cout<<1<<endl;
    for (int i=1;i<=n;i++) cout<<V[i]<<" ";
    cout<<endl;
    for (int i=1;i<n;i++){
        cout<<E[i]<<" ";
    }
    cout<<endl;

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