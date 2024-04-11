#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
//#pragma GCC optimize("unroll-loops")
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
constexpr int N = 1e6+20,mod = 1e9+7 ,inf = 1e9+10,maxm = (1 << 10)+10;
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
int a[N],b[N],vis[N];
ll pre[N],pre2[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    memset(vis,-1,sizeof vis);
    int n;
    cin >> n;
    rep(i,1,n+1){
        cin >> a[i];
        pre[i] = a[i]+pre[i-1];
    }
    rep(i,1,n+1){
        cin >> b[i];
        pre2[i] = b[i]+pre2[i-1];
    }
    bool f = 0;
    if (pre[n] > pre2[n]){
        f = 1;
        rep(i,1,n+1){
            swap(a[i],b[i]);
            swap(pre[i],pre2[i]);
        }
    }
    vis[0] = 0;
    rep(i,1,n+1){
        int j = lower_bound(pre2,pre2+n+1,pre[i])-pre2;
        if (vis[pre2[j]-pre[i]] != -1){
            int g = vis[pre2[j]-pre[i]],v = lower_bound(pre2,pre2+n+1,pre[g])-pre2;
            vector<int> ve[2];
            rep(k,g+1,i+1)
                ve[0].pb(k);
            rep(k,v+1,j+1)
                ve[1].pb(k);
            if (f) swap(ve[0],ve[1]);
            cout << ve[0].size() << endl;
            for (int u : ve[0]) cout << u << ' ';
            cout << endl << ve[1].size() << endl;
            for (int u : ve[1]) cout << u << ' ';
            return 0;
        }
        vis[pre2[j]-pre[i]] = i;
    }
}