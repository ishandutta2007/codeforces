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
typedef pair<int,int> pll;
constexpr int N = 2e5+20,mod = 998244353 ,inf = 1e9+10;

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
int fac[N],inv[N];
string s[N];
int c(int r,int n){
    if (r < 0 || r > n) return 0;
    return 1ll*fac[n]*inv[r]%mod*inv[n-r]%mod;
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    fac[0] = 1;
    inv[0] = 1;
    rep(i,1,N){
        fac[i] = 1ll*i*fac[i-1]%mod;
        inv[i] = poww(fac[i],mod-2);
    }
    int n,b = 0,q = 0;
    bool fl = 0;
    cin >> n;
    rep(i,0,n){
        cin >> s[i];
        if (s[i] == "BB" || s[i] == "WW") fl = 1;
        q += (s[i][0] == '?');
        b += (s[i][0] == 'B');
        q += (s[i][1] == '?');
        b += (s[i][1] == 'B');
    }
    int ans = c(n-b,q);
    if (fl){
        cout << c(n-b,q);
        return 0;
    }
    int cnt[3] = {0,0,0};
    rep(i,0,n){
        if (s[i] == "??"){
            cnt[0]++;
            continue;
        }
        if (s[i][0] == 'W' || s[i][1] == 'B') cnt[1]++;
        else cnt[2]++;
    }
    ans = mkay(ans,-poww(2,cnt[0]));
    if (min(cnt[1],cnt[2])){
        cout << ans;
        return 0;
    }
    ans = mkay(ans,1);
    if (max(cnt[1],cnt[2])) cout << ans;
    else{
        ans = mkay(ans,1);
        cout << ans;
    }

}