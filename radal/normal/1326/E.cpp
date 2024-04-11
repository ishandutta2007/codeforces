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
const int N = 3e5+20,mod = 1e9+7,inf = 2e9,sq = 400;
int poww(int n,ll k){
    if (!k) return 1;
    if (k == 1) return n;
    int r = poww(n,k/2);
    return 1ll*r*r%mod*poww(n,k&1)%mod;
}
inline int mkay(int x,int y){
    if (x+y < mod) return x+y;
    return x+y-mod;
}
int p[N],q[N],n,ind[N],seg[4*N],lz[4*N];
void upd(int l,int r,int s,int e,int x,int v){
    if (l >= s && e >= r){
        lz[v] += x;
        seg[v] += x;
        return;
    }
    if (l >= e || s >= r) return;
    int m = (l+r) >> 1,u = (v << 1);
    if (lz[v]){
        lz[u] += lz[v];
        lz[u|1] += lz[v];
        seg[u] += lz[v];
        seg[u|1] += lz[v];
        lz[v] = 0;
    }
    upd(l,m,s,e,x,u);
    upd(m,r,s,e,x,u|1);
    seg[v] = min(seg[u],seg[u|1]);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i,0,n){
        cin >> p[i];
        ind[p[i]] = i;
    }
    rep(i,0,n){
        cin >> q[i];
        q[i]--;
    }
    int cur = n;
    upd(0,n,0,ind[n]+1,-1,1);
    rep(i,0,n){
        cout << cur << ' ';
        upd(0,n,0,q[i]+1,1,1);
        while(cur > 1 && seg[1] >= 0){
            cur--;
            upd(0,n,0,ind[cur]+1,-1,1);
        }
    }

}