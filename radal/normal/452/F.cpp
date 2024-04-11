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
typedef pair<long double,long double> pld;
const long long int N = 3e5+10,mod = 1e9+7,inf = 1e9,sq = 65,fx = 98765431;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,ll k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int a[N],po[N];
int seg[N*4][3]; // cnt,pre,suf;
void upd(int l,int r,int p,int v){
    if (r-l == 1){
        seg[v][0] = 1;
        seg[v][1] = 1;
        seg[v][2] = 1;
        return;
    }
    int u = (v << 1),m = (l+r) >> 1;
    if (p < m) upd(l,m,p,u);
    else upd(m,r,p,u|1);
    seg[v][0] = seg[u][0]+seg[u|1][0];
    seg[v][1] = mkay(seg[u][1],1ll*seg[u|1][1]*po[seg[u][0]]%mod);
    seg[v][2] = mkay(seg[u|1][2],1ll*seg[u][2]*po[seg[u|1][0]]%mod);
}
int que_cnt(int l,int r,int s,int e,int v){
    if (s <= l && r <= e)
        return seg[v][0];
    if (s >= r || l >= e) return 0;
    int m = (l+r) >> 1,u = (v << 1);
    return que_cnt(l,m,s,e,u)+que_cnt(m,r,s,e,u|1);
}
int que(int l,int r,int s,int e,int v,int x){
    if(s == l && r == e) return seg[v][x];
    int m = (l+r) >> 1, u = (v << 1);
    if (e <= m) return que(l,m,s,e,u,x);
    if (s >= m) return que(m,r,s,e,u|1,x);
    int y = que(l,m,s,m,u,x),z = que(m,r,m,e,u|1,x);
    if (x == 1)
        return mkay(y,1ll*z*po[que_cnt(l,m,s,m,u)]%mod);
    return mkay(z,1ll*y*po[que_cnt(m,r,m,e,u|1)]%mod);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(i,0,n) cin >> a[i];
    po[0] = 1;
    rep(i,1,n+2) po[i] = 1ll*po[i-1]*fx%mod;
    upd(0,n+1,a[0],1);
    rep(i,1,n){
        if (a[i]-1 < n-a[i]){
            if (que(0,n+1,1,a[i]+1,1,1) != que(0,n+1,a[i],2*a[i],1,2)){
                cout << "YES";
                return 0;
            }
        }
        else{
            if (que(0,n+1,2*a[i]-n,a[i]+1,1,1) != que(0,n+1,a[i],n+1,1,2)){
                cout << "YES";
                return 0;
            }
        }
        upd(0,n+1,a[i],1);
    }
    cout << "NO";
}