//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=2010;
const ll inf=1e18;
const ll mod=998244353;
int a[N][N];
vector<int>v[N],u[N];
void solve(int Case){
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
            u[i].push_back(a[i][j]);
            v[j].push_back(a[i][j]);
        }
    }
    for (int i=1;i<=n;i++){
        sort(u[i].begin(),u[i].end());
        u[i].erase(unique(u[i].begin(),u[i].end()),u[i].end());

    }
    for (int i=1;i<=m;i++){
        sort(v[i].begin(),v[i].end());
        v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            int r=lower_bound(u[i].begin(),u[i].end(),a[i][j])-u[i].begin();
            int c=lower_bound(v[j].begin(),v[j].end(),a[i][j])-v[j].begin();
            cout<<max(r,c)+max((int)u[i].size()-r,(int)v[j].size()-c)<<" ";
        }
        cout<<endl;
    }




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