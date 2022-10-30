#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const long long int N=4e6+30,mod = 1e9+7,inf=1e18;
int ans[N];
int main(){
    ll n,m;
    cin >> n >> m;
    set <int> st;
    set <int> :: iterator it;
    rep(i,1,n+1){
        st.insert(i);
    }
    rep (i,0,m){
        int l, r, w;
        cin >> l >> r >> w;
        it = st.lower_bound(l);
        while (!st.empty() && it != st.end() && *it <= r){
            ll it2 = *it;
            if (it2 != w){
                st.erase(it2);
               // debug(*it2);
                ans[it2] = w;
            }
            it = st.upper_bound(it2);
        //    if (it != st.end()) debug(*it);
        }
    }
    rep (i,1,n+1) cout << ans[i] << ' ';
}