#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
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
constexpr int N = 1e5+20,mod = 1e9+7,inf = 1e9+10;
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
        k /= 2;
    } 
    return z; 
}

int cnt,a[N],b[N];
set<int> ind[N];
void solve(){
    rep(i,1,cnt+1) ind[i].clear();
    int n;
    cin >> n;
    cnt = 1;
    rep(i,1,n+1){
        cin >> a[i];
        ind[cnt].insert(i);
    }
    rep(i,1,n+1) cin >> b[i];
    int ans = 0;
    repr(d,29,0){
        bool fl = 1;
        rep(i,1,cnt+1){
            int dlt = 0;
            for (int j : ind[i]){
                if ((a[j]&(1 << d)) == 0) dlt++;
                if (b[j]&(1 << d)) dlt--;
            }
            if (dlt != 0){
                fl = 0;
                break;
            }
        }
        if (!fl) continue;
        ans += (1 << d);
        int nw = 0;
        rep(i,1,cnt+1){
            vector<int> ze,on;
            for (int j : ind[i]){
                if (b[j]&(1 << d)) on.pb(b[j]);
                else ze.pb(b[j]);
            }
            if (ze.empty() || on.empty()) continue;
            nw++;
            vector<int> bad;
            for (int j : ind[i]){
                if (a[j]&(1 << d)){
                    bad.pb(j);
                    b[j] = ze.back();
                    ze.pop_back();
                    ind[cnt+nw].insert(j);
                }
                else{
                    b[j] = on.back();
                    on.pop_back();
                }
            }
            for (int j : bad) ind[i].erase(j);
        }
        cnt += nw;
    }
    cout << ans << endl;
    return;
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}