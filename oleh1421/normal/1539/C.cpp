#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
using namespace std;
//#define int ll
const int N=500055;
const ll mod=1000000007;
const ll inf=1e18;
ll a[N];
void solve(){
    int n;cin>>n;
    ll k,x;cin>>k>>x;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    vector<ll>v;
    for (int i=2;i<=n;i++){
        if (a[i]-a[i-1]<=x) v.push_back(0);
        else v.push_back((a[i]-a[i-1]-1)/x);
    }
    sort(v.begin(),v.end());
    int res=n;
    for (ll i:v){
        if (i>k) break;
        k-=i;
        res--;
    }
    cout<<res<<endl;
}
int32_t main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}

/**
1
6 6
0 0 0 0 0 0
1 1 1 1 1 1
1 2
2 3
1 3
4 5
5 6
4 6
**/
//k*d-d=2
//d*(k-2)=2
//k>1
//d=2