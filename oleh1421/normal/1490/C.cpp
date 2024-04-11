//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const int A=1000001;
const ll mod=1000000007ll;
set<ll>st;
void solve(){
    ll n;cin>>n;
    for (ll i=1;i*i*i<=n;i++){
        if (st.find(n-i*i*i)==st.end()) continue;
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
}
int32_t main()
{
    for (ll i=1;i*i*i<=(ll)1e12;i++){
        st.insert(i*i*i);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;

    while (tt--){
        solve();
    }
    return 0;
}
/*
1
3 3
1 -3 4
1 5 2
*/