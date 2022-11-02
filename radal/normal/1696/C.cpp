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
constexpr int N = 5e5+20,mod = 1e9+7,inf = 1e9+10;
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
inline void solve(){
    int n,m;
    cin >> n >> m;
    vector<pll> ve[2];
    rep(i,0,n){
        cin >> a[i];
        int x = a[i];
        while (x%m == 0) x /= m;
        ve[0].pb({a[i]/x,x});
    }
    int t;
    cin >> t;
    rep(i,0,t){
        cin >> b[i];
        int x = b[i];
        while (x%m == 0) x /= m;
        ve[1].pb({b[i]/x,x});
    }
    int po = 0,po2 = 0,cnt = 0,fl = 0;
    while (po < n && po2 < t){
        if (ve[0][po].Y != ve[1][po2].Y){
            cout << "No" << endl;
            return;
        }
        if (fl){
            if (ve[0][po].X > ve[1][po2].X-cnt){
                cnt = ve[1][po2].X-cnt;
                fl = 0;
                po2++;
                continue;
            }
            if (ve[0][po].X == ve[1][po2].X-cnt){
                po++;
                po2++;
                cnt = 0;
                fl = 0;
                continue;
            }
            cnt += ve[0][po].X;
            po++;
            continue;
        }
        else{
            if (ve[0][po].X < ve[1][po2].X+cnt){
                cnt = ve[0][po].X-cnt;
                fl = 1;
                po++;
                continue;
            }
            if (ve[0][po].X == ve[1][po2].X+cnt){
                po++;
                po2++;
                cnt = 0;
                fl = 0;
                continue;
            }
            cnt += ve[1][po2].X;
            po2++;
            continue;
        }
    }
    if (po < n || po2 < t){
        debug(1);
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
}
int main(){
   ios :: sync_with_stdio(0); cin.tie(0);
   int T = 1;
   cin >> T;
   while (T--){
       solve();
   }
}