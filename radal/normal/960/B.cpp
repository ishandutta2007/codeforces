#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e5+10,mod = 1e9+7,inf=1e18,dlt = 12251,maxm = 1e6+10;
ll poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int a[N],b[N];
int main(){
    int n,k1,k2;
    cin >> n >> k1 >> k2;
    rep(i,0,n) cin >> a[i];
    multiset<ll> st;
    rep(i,0,n){
        cin >> b[i];
        st.insert(abs(a[i]-b[i]));
    }
    rep(i,0,k1+k2){
        int v = *(st.rbegin());
        if (v > 0) v--;
        else v++;
        st.erase(--st.end());
        st.insert(v);
    }

    ll ans = 0;
    for (auto it = st.begin(); it != st.end(); ++it){
        ans += (*it)*(*it);
    }
    cout << ans;
    return 0;
}