#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,avx2")
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
constexpr ll N = 5e5+10,mod = 1e9+7,inf = 1e9+10,maxm = 1e7+2;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k,int md = mod){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%md;
        a = 1ll*a*a%md;
        k /= 2;
    } 
    return z; 
}
int cnt[maxm],g[maxm],pw[N],gc[maxm],mb[maxm];
bitset<maxm> com;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,a;
    cin >> n;
    pw[0] = 1;
    rep(i,0,n){
        cin >> a;
        pw[i+1] = pw[i]+pw[i];
        if (pw[i+1] >= mod) pw[i+1] -= mod;
        cnt[a]++;
    }

    rep(i,1,maxm) mb[i] = 1;

    cnt[1] = n;
    rep(i,2,maxm){
        for (int j = i; j < maxm; j += i){
            if (j > i)
                com[j] = 1;

            if (!com[i]){
                if ((j/i)%i == 0) mb[j] = 0;
                else mb[j] *= -1;
            }

            g[i] += cnt[j];
        }
        cnt[i] = n;
    }

    rep(i,2,maxm){
        if (!mb[i]) continue;
        for (int j = i; j < maxm; j += i){
            cnt[j] += mb[i]*g[i];
        }
    }
    int ans = 0;
    repr(i,maxm-1,2){
        if (!g[i]) continue;
        gc[i] = pw[g[i]]-1;
        for (int j = i+i; j < maxm; j += i)
            gc[i] = mkay(gc[i],-gc[j]);
        ans = mkay(ans,1ll*cnt[i]*gc[i]%mod);
    }
    cout << ans;
    return 0;
}