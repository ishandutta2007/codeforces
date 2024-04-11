#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2")
//#pragma GCC optimize("unroll-loops,O3")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 1e5+5,mod = 1e9+7,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    } 
    return z; 
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    ll x,y;
    ll l,r;
    cin >> x >> y >> l >> r;
    set<pair<ll,ll> > st;
    st.insert({l,r});
    ll z1 = 1,z2 = 1;
    while (1){
        if (st.empty()) break;
        z2 = 1;
        while (1){
            if (st.empty()) break;
            auto it = st.upper_bound({z1+z2,r});
            if (it != st.begin()){
                it--;
                if (it->Y == z1+z2){
                    if (it->X == it->Y){
                        st.erase(it);
                    }
                    else{
                        auto p = (*it);
                        st.erase(it);
                        st.insert({p.X,p.Y-1});
                    }
                }
                else if (it->Y > z1+z2){
                    if (it -> X == z1+z2){
                        ll p = it->Y;
                        st.erase(it);
                        st.insert({z1+z2+1,p});
                    }
                    else{
                        auto p = (*it);
                        st.erase(it);
                        st.insert({z1+z2+1,p.Y});
                        st.insert({p.X,z1+z2-1});
                    }
                }
            }
            if ((r-z1)/y < z2) break;
            z2 *= y;
        }
        if (r/x < z1) break;
        z1 *= x;
    }
    if (st.empty()) cout << 0;
    else{
        ll ans = 0;
        for (auto p : st){
            ans = max(ans,p.Y-p.X+1);
        }
        cout << ans;
    }
    return 0;
}