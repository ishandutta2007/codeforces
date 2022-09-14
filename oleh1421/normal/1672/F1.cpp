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
vector<int>g[N];
vector<int>cyc[N];
int b[N];
void solve(){
    int n;cin>>n;
    for (int i=0;i<=n;i++) g[i].clear(),cyc[i].clear();
    for (int i=1;i<=n;i++) cin>>a[i],g[a[i]].push_back(i);
    for (int i=1;i<=n;i++){
        for (int j=0;j<g[i].size();j++){
            cyc[j].push_back(g[i][j]);
        }
    }
    for (int i=0;i<n;i++){
        if (!cyc[i].empty()){
            int sz=cyc[i].size();
            for (int j=0;j<sz;j++){
                b[cyc[i][j]]=a[cyc[i][(j+1)%sz]];
//                cout<<cyc[i][j]<<" "<<cyc[i][(j+1)%sz]<<endl;
            }
        }
    }
    for (int i=1;i<=n;i++) cout<<b[i]<<" ";
    cout<<endl;



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