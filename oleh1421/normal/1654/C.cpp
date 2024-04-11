//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
mt19937 rnd(time(NULL));
const int N=2000010;
const ll mod=998244353;
const int L=20;
const ll inv2=(mod+1)/2;
ll binpow(ll a,ll b){
    if (!b) return 1ll;
    if (b%2) return binpow(a,b-1)*a%mod;
    else return binpow(a*a%mod,b/2ll);
}
void solve(){
    int n;cin>>n;
    multiset<ll>st;
    ll sum=0ll;
    for (int i=1;i<=n;i++) {
        ll x;cin>>x;
        st.insert(x);
        sum+=x;
    }
    vector<ll>have={sum};
    while (!st.empty()){
        vector<ll>nxt;
        for (ll i:have){
            auto it=st.find(i);
            if (it==st.end()){
                if (i==1){
                    cout<<"NO\n";
                    return;
                }
                nxt.push_back(i/2);
                nxt.push_back((i+1)/2);
                continue;
            }
            st.erase(it);
        }
        have=nxt;
        if (have.size()>st.size()){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";


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

//2
//
//1 2

/**


**/