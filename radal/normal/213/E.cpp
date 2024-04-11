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
const int N = 2e5+20,mod = 1e9+7,inf = 2e9,sq = 400;
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
int a[N],b[N],seg[4*N][2],hsh,pre[N],ind[N];
void upd(int l,int r,int p,int v){
    if (r-l == 1){
        seg[v][0] = 1;
        seg[v][1] = b[p];
        return;
    }
    int m = (l+r)/2,u = (v << 1);
    if (p < m) upd(l,m,p,u);
    else upd(m,r,p,u+1);
    seg[v][0] = seg[u][0]+seg[u|1][0];
    seg[v][1] = mkay(seg[u][1],1ll*seg[u|1][1]*poww(987654321,seg[u][0])%mod);
}
void upd2(int l,int r,int p,int v){
    if (r-l == 1){
        seg[v][0] = 0;
        seg[v][1] = 0;
        return;
    }
    int m = (l+r)/2,u = (v << 1);
    if (p < m) upd2(l,m,p,u);
    else upd2(m,r,p,u+1);
    seg[v][0] = seg[u][0]+seg[u|1][0];
    seg[v][1] = mkay(seg[u][1],1ll*seg[u|1][1]*poww(987654321,seg[u][0])%mod);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    rep(i,0,n){
        cin >> a[i];
        int po = poww(987654321,i);
        hsh = mkay(hsh,1ll*a[i]*po%mod);
        pre[i] = po;
        if (i) pre[i] = mkay(pre[i-1],pre[i]);
    }
    rep(i,0,m){
        cin >> b[i];
        ind[b[i]] = i;
    }
    int ans = 0;
    rep(j,0,m-n+1){
        if(!j) rep(i,1,n+1) upd(0,m,ind[i],1);
        else{
            upd2(0,m,ind[j],1);
            upd(0,m,ind[n+j],1);
        }
        if (seg[1][1] == hsh) ans++;
        hsh = mkay(hsh,pre[n-1]);
    }
    cout << ans;
}