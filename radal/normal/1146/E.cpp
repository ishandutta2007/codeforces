#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N = 2e5+20,mod = 1e9+7,inf=1e9,maxm = 1e5+1;
int a[N],seg[4*N][2],lz[4*N],b[N];
void build(int l,int r,int v){
    seg[v][0] = r-l;
    seg[v][1] = 0;
    if(r-l > 1){
        int m = (l+r)/2;
        build(l,m,2*v);
        build(m,r,2*v+1);
    }
}
inline void push(int l,int r,int v){
    if (lz[v] == -1 || r-l == 1) return;
    int u = 2*v,m = (l+r)/2;
    if (lz[v] == 2){
        int x = seg[u][0];
        seg[u][0] = seg[u][1];
        seg[u][1] = x;
        if (lz[u] == 0) lz[u] = 1;
        else if (lz[u] == 1) lz[u] = 0;
        else if (lz[u] == 2) lz[u] = -1;
        else lz[u] = 2;
        x = seg[u|1][0];
        seg[u|1][0] = seg[u|1][1];
        seg[u|1][1] = x;
        if (lz[u|1] == 0) lz[u|1] = 1;
        else if (lz[u|1] == 1) lz[u|1] = 0;
        else if (lz[u|1] == 2) lz[u|1] = -1;
        else lz[u|1] = 2;
        lz[v] = -1;
        return;
    }
    if (lz[v] == 0){
        seg[u][0] = m-l;
        seg[u][1] = 0;
        seg[u+1][0] = r-m;
        seg[u+1][1] = 0;
    }
    else{
        seg[u][1] = m-l;
        seg[u][0] = 0;
        seg[u+1][1] = r-m;
        seg[u+1][0] = 0;
    }
    lz[u] = lz[u+1] = lz[v];
    lz[v] = -1;
}
void upd3(int l,int r,int s,int e,int v){
    if (l >= e || s >= r) return;
    if (l >= s && e >= r){
        int x = seg[v][0];
        seg[v][0] = seg[v][1];
        seg[v][1] = x;
        if (lz[v] == -1) lz[v] = 2;
        else if (lz[v] == 2) lz[v] = -1;
        else
            lz[v] = 1-lz[v];
        return;
    }
    int m = (l+r)/2;
    push(l,r,v);
    upd3(l,m,s,e,2*v);
    upd3(m,r,s,e,2*v+1);
    seg[v][0] = seg[2*v][0] + seg[2*v+1][0];
    seg[v][1] = seg[2*v][1] + seg[2*v+1][1];
}
void upd2(int l,int r,int p,int v,bool f){
    if (l >= p){
        if (!f){
            seg[v][0] = r-l;
            seg[v][1] = 0;
        }
        else{
            seg[v][0] = 0;
            seg[v][1] = r-l;
        }
        lz[v] = f;
        return;
    }
    if (r <= p) return;
    int m = (l+r)/2;
    push(l,r,v);
    upd2(l,m,p,2*v,f);
    upd2(m,r,p,2*v+1,f);
    seg[v][0] = seg[2*v][0]+seg[2*v+1][0];
    seg[v][1] = seg[2*v][1]+seg[2*v+1][1];
}
void upd(int l,int r,int p,int v,bool f){
    if (r <= p){
        if (!f){
            seg[v][0] = r-l;
            seg[v][1] = 0;
        }
        else{
            seg[v][0] = 0;
            seg[v][1] = r-l;
        }
        lz[v] = f;
        return;
    }
    if (l >= p) return;
    int m = (l+r)/2;
    push(l,r,v);
    upd(l,m,p,2*v,f);
    upd(m,r,p,2*v+1,f);
    seg[v][0] = seg[2*v][0]+seg[2*v+1][0];
    seg[v][1] = seg[2*v][1]+seg[2*v+1][1];
}
bool que(int l,int r,int p,int v){
    if (r-l == 1){
        return seg[v][0];
    }
    int m = (l+r)/2;
    push(l,r,v);
    if (p < m) return que(l,m,p,2*v);
    return que(m,r,p,2*v+1);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    memset(lz,-1,sizeof lz);
    int n,q;
    cin >> n >> q;
    rep(i,0,n) cin >> a[i];
    build(0,N,1);
    while(q--){
        char c;
        int x;
        cin >> c >> x;
        if (c == '<'){
            if (x <= 0){
                upd(0,N,maxm+x,1,1);
                upd2(0,N,maxm-x+1,1,0);
            }
            else{
                upd3(0,N,maxm-x+1,maxm+x,1);
                upd(0,N,maxm-x+1,1,1);
                upd2(0,N,maxm+x,1,0);
            }
        }
        else{
            if (x >= 0){
                upd(0,N,maxm-x,1,0);
                upd2(0,N,maxm+x+1,1,1);
            }
            else{
                upd3(0,N,maxm+x+1,maxm-x,1);
                upd(0,N,maxm+x+1,1,0);
                upd2(0,N,maxm-x,1,1);
            }
        }
    }
    rep(i,-maxm,maxm){
        if (que(0,N,maxm+i,1)) b[maxm+i] = i;
        else b[maxm+i] = -i;
    }
    rep(i,0,n) cout << b[a[i]+maxm] << ' ';
    return 0;
}