#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
#pragma GCC optimize("unroll-loops,O2")
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
constexpr int N = 3e5+20,mod = 998244353 ,inf = 1e9+10;

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
int sp[N][20],a[N],lg[N];
map<int,vector<int> > ind;
int que(int l,int r){
    int j = lg[r-l+1];
    return gcd(sp[r][j],sp[l+(1 << j)-1][j]);
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    lg[1] = 0;
    rep(i,2,n+1) lg[i] = lg[i/2]+1;
    rep(i,0,n){
        cin >> a[i];
        sp[i][0] = a[i];
        ind[a[i]].pb(i);
    }
    rep(j,1,20){
        rep(i,(1 << j)-1,n){
            sp[i][j] = gcd(sp[i][j-1],sp[i-(1 << (j-1))][j-1]);
        }
    }
    int q;
    cin >> q;
    while (q--){
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        int g = que(l,r);
        cout << r-l+1-(upper_bound(all(ind[g]),r)-lower_bound(all(ind[g]),l)) << endl;
    }
}