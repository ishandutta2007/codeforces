//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=500010;
const ll mod=1000000007;
int a[N],b[N];
void solve(){
    int n,m;cin>>n;
    ll sumn=0ll;
    ll mxn=0ll;
    for (int i=1;i<=n;i++){
        ll x;cin>>x;
        sumn+=x;
        mxn=max(mxn,sumn);
    }
    cin>>m;
    ll summ=0ll;
    ll mxm=0ll;
    for (int i=1;i<=m;i++){
        ll x;cin>>x;
        summ+=x;
        mxm=max(mxm,summ);
    }
    cout<<mxn+mxm<<endl;
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }

    return 0;
}