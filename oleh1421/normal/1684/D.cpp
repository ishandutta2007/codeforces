//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;
typedef long double ld;
typedef long long ll;
//#define int ll
const int N=500105;
const ll inf=1e9;
const ll mod=1000000007;
const int L=20;
ll a[N];
void solve(int Case){
    ll n,k;cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    ll sum=0ll;
    for (int i=1;i<=n;i++) sum+=a[i];
    for (int i=1;i<=k;i++) sum+=(n-k+i);
    vector<ll>v;
    for (int i=1;i<=n;i++){
        v.push_back(-a[i]-i);
    }
    sort(v.begin(),v.end());
    for (int i=0;i<k;i++) sum+=v[i];
    cout<<sum<<endl;
}
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    for (int it=1;it<=tt;it++){
        solve(it);
    }
    return 0;
}
/**
9 10 0 8
0 1
1 2
2 3
3 4
1 4
4 5
7 5
6 7
0 6
7 8



**/