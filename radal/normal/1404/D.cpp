#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
//#pragma GCC optimize("unroll-loops,O2")
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
constexpr int N = 1e6+10,mod = 1e9+7,inf = 1e9+10;
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
int p[N],n,to,k;
pll a[N];
bool vis[N],mark[N];
void dfs(int v,bool f){
    if (vis[v]) return;
    to++;
    mark[v] = f;
    k += f;
    vis[v] = 1;
    int u,fl = 0;
    if (f){
        if (a[p[v]].X == v) u = a[p[v]].Y;
        else u = a[p[v]].X;
    }
    else{
        if (a[p[v+n]].X == v+n) u = a[p[v+n]].Y;
        else u = a[p[v+n]].X;
    }
    if (u > n){
        u -= n;
        fl = 1;
    }
    dfs(u,fl);
}
int main(){
 //   ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    if (n%2 == 0){
        cout << "First" << endl;
        rep(j,0,2){
            rep(i,1,n+1){
                cout << i << ' ';
            }
        }
        cout << endl;
        return 0;
    }
    cout << "Second" << endl;
    n *= 2;
    rep(i,1,n+1){
        cin >> p[i];
        if (a[p[i]].X) a[p[i]].Y = i;
        else a[p[i]].X = i;
    }
    n /= 2;
    int j = -1;
    rep(i,1,n+1){
        if (!vis[i]){
            dfs(i,0);
            if (to&1)
                j = i;
            to = 0;
        }
    }
    if ((n%4 == 3 && k%2) || (n%4 == 1 && k%2 == 0)){
        memset(vis,0,sizeof vis);
        dfs(j,1);
    }
    rep(i,1,n+1)
        cout << ((mark[i]) ? i+n : i) << ' ';
    return 0;
}