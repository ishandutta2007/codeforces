#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define endl '\n'
using namespace __gnu_pbds;
typedef long double ld;
//#define int ll
using namespace std;
mt19937 rnd(time(NULL));
typedef long long ll;
const ll mod=998244353;
const ll inf=1000000000000000001;
const int N=300010;
int a[N];
int b[N];
vector<int>g[N];
bool CYC=false;
int used[N];
int cnt[N];
void dfs(int v){
    used[v]=1;
    for (int to:g[v]){
        if (used[to]){
            if (used[to]==1) CYC=true;
        } else {
            dfs(to);
        }
    }
    used[v]=2;
}
void solve(){
    int n;cin>>n;
    CYC=false;
    for (int i=0;i<=n;i++){
        used[i]=0;
        g[i].clear();
        cnt[i]=0;
    }
    for (int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++){
        g[a[i]].push_back(b[i]);
    }
    int mx=0;
    for (int i=1;i<=n;i++){
        if (cnt[i]>cnt[mx]) mx=i;
    }
    used[mx]=2;
    for (int i=1;i<=n;i++){
        if (used[i]==0){
            dfs(i);
        }
    }
    if (CYC) cout<<"WA\n";
    else cout<<"AC\n";




}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}

/**
1
5
1 2 4 2 1
4 2 2 1 1
  ,        .
**/