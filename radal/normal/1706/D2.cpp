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
constexpr int N = 1e5+20,mod = 1e9+7,inf = 1e9+10,sq = 500;
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
int nxt[N],a[N];
void solve(){
    int n,k;
    cin >> n >> k;
    rep(i,0,n) cin >> a[i];
    if (a[n-1] <= k){
        cout << 0 << endl;
        return;
    }
    int po = 0;
    rep(i,1,N){
        while (po < n && a[po] < i) po++;
        nxt[i] = po;
    }
    int ans = inf;
    rep(i,1,a[n-1]+1){
        if (a[n-1]/k > i) continue;
        int cur = i+1,j = 2;
        int mi = inf;
        if (a[0] < cur) mi = a[0];
        while (j <= k && cur <= a[n-1]){
            if (j == k || a[nxt[cur]] < cur+i+1){
                mi = min(mi,a[nxt[cur]]/j);
            }
            j++;
            cur += i+1;
        }
        ans = min(ans,i-mi);
    }
    cout << ans << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}