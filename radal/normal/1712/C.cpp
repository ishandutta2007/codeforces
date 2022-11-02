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
constexpr long long int N = 1e5+20,mod = 1e9+7 ,inf = 1e9+10;
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

int a[N],mi[N],mx[N];
bool cmp(int v,int u){
    return (mi[v] < mi[u]);
}
inline void solve(){
    int n;
    cin >> n;
    rep(i,1,n+1){
        mx[i] = -1;
        mi[i] = inf;
    }
    rep(i,0,n){
        cin >> a[i];
        mi[a[i]] = min(mi[a[i]],i);
        mx[a[i]] = i;
    }
    vector <int> ve;
    rep(i,1,n+1) if (mx[i] != -1) ve.pb(i);
    sort(all(ve),cmp);
    int j = -1;
    repr(i,n-2,0){
        if (a[i] > a[i+1]){
            j = i;
            break;
        }
    }
    if (j == -1){
        cout << 0 << endl;
        return;
    }
    int po = 0,sz = ve.size();
    while (po < sz){
        if (mi[ve[po]] > j) break;
        j = max(j,mx[ve[po]]);
        po++;
    }
    cout << po << endl;
}
int main(){
    ios:: sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}