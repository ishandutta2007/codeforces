#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
int ans[N],a[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin >> n >> k;
    rep(i,0,n){
        cin >> a[i];
    }
    multiset<int> st;
    int ind = 0;
    st.insert(a[0]);
    rep(i,0,n){
        if (ind < i){
            st.insert(a[i]);
            ind++;
        }
        int mx = *(st.rbegin()),mi = *(st.begin());
        while (ind+1 < n && max(mx,a[ind+1])-min(mi,a[ind+1]) <= k){
            ind++;
            st.insert(a[ind]);
            mx = *(st.rbegin());
            mi = *(st.begin());
        }
        ans[i] = ind+1;
        auto idx = st.lower_bound(a[i]);
        st.erase(idx);
    }
    int mx = 0;
    vector<pll> ve;
    rep(i,0,n){
        if (ans[i]-i > mx){
            mx = ans[i]-i;
            ve.clear();
            ve.pb({i+1,ans[i]});
        }
        else if(ans[i]-i == mx) ve.pb({i+1,ans[i]});
    }
    cout << mx << ' ' << ve.size() << endl;
    for (pll u : ve) cout << u.X << ' ' << u.Y << endl;
    return 0;
}