#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
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
constexpr int N = 3e5+20,mod = 1e9+7 ,inf = 1e9+10,maxm = (1 << 10)+10;
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
int x[N],r[N],l[N],p[N];
ll pre[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    rep(i,0,n){
        cin >> p[i];
        pre[i] = p[i];
        if (i) pre[i] += pre[i-1];
    }
    rep(i,0,m)
        cin >> x[i];
    sort(x,x+m);
    int po = 0;
    ll ans = 0;
    rep(i,0,n){
        while (po < m && x[po] < i*100)
            po++;
        if (!po) l[i] = -inf;
        else l[i] = x[po-1];
        if (po < m) r[i] = x[po];
        else r[i] = inf;
        if (r[i] == i*100) continue;
        int y = min({(n-1)*100,r[i],i*200-l[i]});
        ll sum = 0;
        if (i) sum -= pre[i-1];
        int mx = min((n-1)*100,(r[i]+y+1)/2-1);
        sum += pre[mx/100];
        ans = max(ans,sum);
    }
    cout << ans;
}