#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
#define int ll
const int N=500010;
const ll inf=1e18;
const ll mod=998244353;
vector<int>rg[N];
int d[N];
int p[N];
int cnt[N];
void solve(int Case){
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        rg[b].push_back(a);
    }

    int k;cin>>k;
    for (int i=1;i<=k;i++) cin>>p[i];
    for (int i=1;i<=n;i++) d[i]=-1;
    queue<int>q;
    d[p[k]]=0;
    q.push(p[k]);
    while (!q.empty()){
        int v=q.front();
        q.pop();
//        cout<<v<<" "<<d[v]<<endl;
        for (int to:rg[v]){
            if (d[to]==-1){
                d[to]=d[v]+1;
                q.push(to);
            }
        }
    }
    for (int i=1;i<=n;++i){
        for (int to:rg[i]){
            if (d[to]==d[i]+1) cnt[to]++;
        }
    }
    int mn=0,mx=0;
    for (int i=1;i<k;i++){
        if (d[p[i]]!=d[p[i+1]]+1){
//            cout<<p[i]<<" "<<d[p[i]]<<" "<<d[p[i+1]]<<endl;
            mn++;
            mx++;
        } else if (cnt[p[i]]>1) mx++;
    }
    cout<<mn<<" "<<mx<<endl;




}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}

/**
problem B with higher constrains


3
1 R
5 R
10 R
100 G
3 G
7 G


1
4
2 3 1 4

8 1
1 3 5 2 4 7 6 8
1 8


1
5 2
-1 1 2 0 0


4 11

3 6
2 3
1 1

2 3
999999999 1000000000
**/