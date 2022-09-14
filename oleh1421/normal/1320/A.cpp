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
ll b[N];
void solve(int Case){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>b[i];
    map<int,int>mp;
    int res=0;
    for (int i=1;i<=n;i++) {
        mp[i-b[i]]+=b[i];
    }
    for (auto cur:mp) res=max(res,cur.second);
    cout<<res<<endl;

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