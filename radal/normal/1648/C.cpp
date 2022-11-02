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
constexpr int N = 2e5+20,mod = 998244353,inf = 1e9+10;
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
int a[N],b[N],fen[N],fac[N],co[N];
int calc[N],t[N],inv[N];
void upd(int r,int x){
    for (; r < N; r |= (r+1))
        fen[r] += x;
}
int que(int l){
    int ans = 0;
    for (; l >= 0; l = (l&(l+1))-1)
        ans += fen[l];
    return ans;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    fac[0] = 1;
    inv[0] = 1;
    rep(i,0,n){
        fac[i+1] = 1ll*(i+1)*fac[i]%mod;
        inv[i+1] = poww(fac[i+1],mod-2);
        cin >> a[i];
        co[a[i]]++;
        upd(a[i],1);
    }
    int ans = 0,lst = m-1;
    rep(i,0,m){
        if (i == n){
            calc[i] = 1;
            lst = i;
            break;
        }
        cin >> b[i];
        int cnt = que(b[i]-1);
        calc[i] = 1ll*cnt*fac[n-i-1]%mod;
        t[i] = que(b[i])-cnt;
        lst = i;
        if (!t[i]) break;
        upd(b[i],-1);
    }
    memset(fen,0,sizeof fen);
    rep(i,0,n) upd(a[i],1);
    ans = calc[lst];
    repr(i,lst-1,0){
        ans = mkay(1ll*ans*t[i]%mod,calc[i]);
    }
    rep(i,1,N) if (co[i]) ans = 1ll*ans*inv[co[i]]%mod;
    cout << ans;
    return 0;
}