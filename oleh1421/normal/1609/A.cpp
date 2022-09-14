#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=500010;
const ll inf=1e18;
const ll mod=998244353;
ll a[N];
void solve(int Case){
    int n;cin>>n;
    ll mult=1ll;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        while (a[i]%2==0){
            mult*=2ll;
            a[i]/=2ll;
        }
    }
    ll mx=a[1];
    ll sum=a[1];
    for (int i=2;i<=n;i++) mx=max(mx,a[i]),sum+=a[i];

    cout<<mx*mult-mx+sum<<endl;



}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;cin>>tt;
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