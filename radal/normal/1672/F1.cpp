#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
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
constexpr int N = 5e5+20,mod = 1e9+7 ,inf = 1e9+10,maxm = (1 << 10)+10;
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
int a[N],b[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        multiset<pll> st;
        rep(i,0,n){ 
            cin >> a[i];
            st.insert({a[i],i});
        }
        while (!st.empty()){
            pll p = *(st.begin());
            st.erase(st.begin());
            vector<int> ind;
            ind.pb(p.Y);
            while (!st.empty()){
                auto it = st.lower_bound({p.X+1,0});
                if (it == st.end()) break;
                p = *it;
                st.erase(it);
                ind.pb(p.Y);
            }
            int sz = ind.size();
            rep(i,0,sz-1){
                b[ind[i]] = a[ind[i+1]];
            }
            b[ind[sz-1]] = a[ind[0]];
        }
        rep(i,0,n) cout << b[i] << ' ';
        cout << endl;
    }
}