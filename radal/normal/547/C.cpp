#include <bits/stdc++.h>
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 5e5+20,mod = 1e9+7,inf = 1e9+10,maxm = (1 << 20);
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
vector<int> ta[N];
bool pr[N],f[N];
int cnt[N],z[N][70],a[N];
ll ans;
inline void rem(int x){
    int y = (1 << (ta[x].size()));
    rep(i,0,y){
        cnt[z[x][i]]--;
        if ((__builtin_popcount(i)&1)) ans += cnt[z[x][i]];
        else ans -= cnt[z[x][i]];
    }
}
inline void add(int x){
    int y = (1 << (ta[x].size()));
    rep(i,0,y){
        if ((__builtin_popcount(i)&1)){
            ans -= cnt[z[x][i]];
        }
        else{
            ans += cnt[z[x][i]];
        }
        cnt[z[x][i]]++;
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    rep(i,2,N){
        if (pr[i]) continue;
        ta[i].pb(i);
        for (int j = (i << 1); j < N; j += i){
            ta[j].pb(i);
            pr[j] = 1;
        }
    }
    rep(i,1,N){
        z[i][0] = 1;
        int y = (1 << (ta[i].size()));
        rep(j,1,y){
            int g = (j&(-j)),cnt = __builtin_ctz(g);
            z[i][j] = z[i][(j^g)]*ta[i][cnt];
        }
    }
    int n,q;
    cin >> n >> q;
    rep(i,0,n){
        cin >> a[i];
    }
    while (q--){
        int i;
        cin >> i;
        i--;
        if (!f[i]) add(a[i]);
        else rem(a[i]);
        f[i] = 1-f[i];
        cout << ans << endl;
    }
}