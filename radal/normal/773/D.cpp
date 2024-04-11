#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
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
constexpr int N = 2e3+20,mod = 1e9+7 ,inf = 1e9+10;
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
int n;
ll a[N][N],d[N],mi[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(mi,63,sizeof mi);
    ll l = 1ll*inf*inf;
    cin >> n;
    rep(i,0,n){
        rep(j,i+1,n){
            cin >> a[i][j];
            l = min(l,a[i][j]);
            mi[i] = min(mi[i],a[i][j]);
            a[j][i] = a[i][j];
            mi[j] = min(mi[j],a[i][j]);
        }
    }
    rep(i,0,n){
        rep(j,0,n)
            if (j != i)
                a[i][j] -= l;
        mi[i] -= l;
    }
    set<pll> st;
    rep(i,0,n){
        d[i] = 2*mi[i];
        st.insert({d[i],i});
    }
    while (!st.empty()){
        pll p = *(st.begin());
        st.erase(p);
        rep(i,0,n){
            if (p.X+a[p.Y][i] < d[i]){
                st.erase({d[i],i});
                d[i] = p.X+a[p.Y][i];
                st.insert({d[i],i});
            }
        }
    }
    rep(i,0,n) cout << d[i]+1ll*l*(n-1) << endl;
}