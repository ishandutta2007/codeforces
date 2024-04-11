#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N = 3e5+20,mod = 998244353,inf = 1e9,sq = 400;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int n,a[N];
ll fen[N][2];
int fen2[N];
inline void upd1(int l,bool f,int x){
    for(; l <= n; l |= (l+1))
        fen[l][f] += x;
}

inline ll que1(int r,bool f){
    ll ans = 0;
    for (; r >= 0; r = (r&(r+1))-1)
        ans += fen[r][f];
    return ans;
}

inline void upd2(int l){
    for (; l <= n; l |= (l+1))
        fen2[l]++;
}

inline int que2(int r){
    int ans = 0;
    for (; r >= 0; r = (r&(r+1))-1)
        ans += fen2[r];
    return ans;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i,1,n+1) cin >> a[i];
    long double ans = 0,d = 1ll*n*(n+1)/2;
    rep(i,1,n+1){
        ll p = que1(a[i],0);
        ans += p*(n-i+1)/d/2;
        upd1(a[i],0,i);
        p = que1(n-a[i],1);
        int cnt = que2(n-a[i]);
        upd2(n-a[i]);
        upd1(n-a[i],1,i);
        ans += cnt;
        ans -= p*(n-i+1)/d/2;
    }
    cout << setprecision(10) << fixed << ans;
}