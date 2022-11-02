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
const int N = 3e5+20,mod = 1e9+7,inf = 2e9,sq = 800+10;
int poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    int r = poww(a,k/2);
    return 1ll*r*r%mod*poww(a,k&1)%mod;
}
pair<pll,pll> a[N];
pll seg[4*N];
int lz[4*N];
/*int que(int l,int r,int s,int e,int v){
    if (l >= s && e >= r)
        return seg[v];
    if (l >= e || s >= r) return 0;
    int m = (l+r) >> 1, u = (v << 1);
    if (lz[v]){
        seg[u] += lz[v];
        seg[u|1] += lz[v];
        lz[u] += lz[v];
        lz[u|1] += lz[v];
        lz[v] = 0;
    }
    return max(que(l,m,s,e,u),que(m,r,s,e,u|1));
}*/
void build(int l,int r,int v){
    seg[v] = {0,l};
    if (r-l == 1) return;
    int m = (l+r)/2;
    build(l,m,2*v);
    build(m,r,2*v+1);
}
void upd(int l,int r,int s,int e,int v,int x){
    if(l >= s && e >= r){
        seg[v].X += x;
        lz[v] += x;
        return;
    }
    if (l >= e || s >= r) return;
    int u = (v << 1),m = (l+r) >> 1; 
    if (lz[v]){
        seg[u].X += lz[v];
        seg[u|1].X += lz[v];
        lz[u] += lz[v];
        lz[u|1] += lz[v];
        lz[v] = 0;
    }
    upd(m,r,s,e,u|1,x);
    upd(l,m,s,e,u,x);
    seg[v] = max(seg[u],seg[u|1]);
}
int main(){
   // ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    rep(i,0,n){
        cin >> a[i].X.X >> a[i].X.Y >> a[i].Y.X;
        a[i].Y.Y = i;
    }
    sort(a,a+n);
    build(0,3e5+1,1);
    priority_queue<pll> pq;
    int mx = 0,L = 0, R = 0;
    rep(i,0,n){
        pq.push({-a[i].X.Y,a[i].Y.X});
        while (-pq.top().X < a[i].X.X){
            pll p = pq.top();
            upd(0,3e5+1,-p.X,p.Y+1,1,-1);
            pq.pop();
        }
        upd(0,3e5+1,a[i].X.Y,a[i].Y.X+1,1,1);
        if (seg[1].X > mx){
            mx = seg[1].X;
            R = seg[1].Y;
            L = a[i].X.X;
        }
    }
    cout << mx << endl;
    rep(i,0,n)
        if (a[i].X.X <= L && a[i].X.Y <= R && a[i].X.Y >= L && a[i].Y.X >= R)
            cout << a[i].Y.Y + 1 << ' ';
        
    
}