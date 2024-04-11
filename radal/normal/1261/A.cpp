#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O3")
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
constexpr int N = 5e5+10,mod = 1e9+7,inf = 1e9+10;
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
void solve(){
    int n,k;
    string s,t = "";
    cin >> n >> k >> s;
    rep(i,1,k){
        t += '(';
        t += ')';
    }
    int ll = n/2-(k-1);
    rep(i,0,ll) t += '(';
    rep(i,0,ll) t += ')';
    vector<pll> ans;
    rep(i,0,n){
        if (s[i] == t[i]) continue;
        int k = -1;
        rep(j,i+1,n){
            if (s[j] == t[i]){
                k = j;
                break;
            }
        }
        ans.pb({i,k});
        int po = i,po2 = k;
        while (po < po2){
            swap(s[po],s[po2]);
            po++;
            po2--;
        }
    }
    cout << ans.size() << endl;
    for (pll p : ans) cout << p.X+1 << ' ' << p.Y+1 << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}