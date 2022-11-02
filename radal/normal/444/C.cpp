#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
ll seg[N*4],dif[N*4];;
int a[N],lz[N*4];
ll que(int l,int r,int s,int e,int v){
    if (l == s && e == r)
        return seg[v];
    if (r <= s || e <= l) return 0;
    int m = (l+r)/2;
    if (e <= m)
        return que(l,m,s,e,2*v)+1ll*dif[v]*(e-s);
    if (s >= m)
        return que(m,r,s,e,2*v+1)+1ll*dif[v]*(e-s);
    return que(l,m,s,m,2*v)+que(m,r,m,e,2*v+1)+1ll*dif[v]*(e-s);
}
void build(int l,int r,int v){
    if (r-l == 1){
        lz[v] = a[l];
        return;
    }
    int m = (l+r)/2;
    build(l,m,2*v);
    build(m,r,2*v+1);
}
void pass(int l, int r, int v,int x){
	if (lz[v]) {
		dif[v] += abs(lz[v] - x);
		seg[v] += 1ll*abs(lz[v] - x)*(r-l);
        lz[v] = x;
	}
    else{
        int m = (l+r)/2;
		pass(m,r,2*v+1,x);
		pass(l,m,2*v,x);
		seg[v] = seg[v*2]+seg[v*2+1]+1ll*dif[v]*(r-l);
        lz[v] = 0;
	}
}
void upd(int l,int r,int s,int e,int v,int x){
    if (r <= s || e <= l) return;
    if (r <= e && s <= l){
        pass(l,r,v,x);
        lz[v] = x;
        return;
    }
    int m = (l+r)/2;
    if (lz[v]) lz[2*v] = lz[2*v+1] = lz[v];
    lz[v] = 0;
    upd(l,m,s,e,2*v,x);
    upd(m,r,s,e,2*v+1,x);
    seg[v] = seg[2*v]+seg[2*v+1]+1ll*(r-l)*dif[v];
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin >> n >> q;
    rep(i,0,n) a[i] = i+1;
    build(0,n,1);
    rep(i,0,q){
        int t,l,r;
        cin >> t >> l >> r;
        l--;
        if (t == 2){
            cout << que(0,n,l,r,1) << endl;
            continue;
        }
        int x;
        cin >> x;
        upd(0,n,l,r,1,x);
    }
    return 0;
}