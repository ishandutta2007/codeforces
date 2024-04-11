#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
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
int cnt[61],n,h[N],ans,par[N];
ll a[N];
int mi;
bool vis[N];
void bfs(int v){
    vis[v] = 1;
    queue<int> q;
    q.push(v);
    par[v] = -1;
    while (!q.empty()){
        int j = q.front();
        q.pop();
        rep(i,mi,n){
            if (i == j || (a[i]&a[j]) == 0) continue;
            if (vis[i]){
                if (i != par[j]) ans = min(ans,h[i]+h[j]+1);
            }
            else{
                vis[i] = 1;
                par[i] = j;
                h[i] = h[j]+1;
                q.push(i);
            }
        }
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    ans = inf;
    rep(i,0,n){
        cin >> a[i];
        rep(j,0,60){
            if (a[i]&(1ll << j)){
                cnt[j]++;
            }
        }
    }
    rep(i,0,60){
        if (cnt[i] >= 3){
            cout << 3;
            return 0;
        }
    }
    sort(a,a+n);
    while (mi < n && !a[mi]) mi++;
    rep(i,mi,n){
        memset(vis,0,sizeof vis);
        h[i] = 0;
        bfs(i);
    }
    if (ans < inf) cout << ans;
    else cout << -1;
}