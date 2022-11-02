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
const int N = 5e5+20,mod = 1e9+7,inf = 2e9,sq = 800+10;
int seg[4*N],a[N];
void build(int l,int r,int v){
    if (r-l == 1){
        seg[v] = a[l];
        return;
    }
    int m = (l+r)/2;
    build(l,m,2*v);
    build(m,r,2*v+1);
    seg[v] = gcd(seg[2*v+1],seg[2*v]);
}
void upd(int l,int r,int p,int v,int x){
    if (r-l == 1){
        a[l] = x;
        seg[v] = x;
        return;
    }
    int m = (l+r)/2;
    if (p < m) upd(l,m,p,2*v,x);
    else upd(m,r,p,2*v+1,x);
    seg[v] = gcd(seg[2*v],seg[2*v+1]);
}
int check(int l,int r,int v,int x){
    if(seg[v]%x == 0)
        return 0;
    if (r-l == 1) return 1;
    int m = (l+r) >> 1,u = (v << 1);
    if (seg[u]%x == 0)
        return check(m,r,u|1,x);
    if (seg[u|1]%x == 0)
        return check(l,m,u,x);
    return 2;
}
int que(int l,int r,int s,int e,int v,int x){
    if (s >= r || l >= e) return 0;
    if (s <= l && r <= e)
        return check(l,r,v,x);
    int m = (l+r)/2,u = (v << 1);
    return que(l,m,s,e,u,x)+que(m,r,s,e,u|1,x);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,q;
    cin >> n;
    rep(i,1,n+1) cin >> a[i];
    cin >> q;
    build(1,n+1,1);
    rep(i,0,q){
        int t,l,r;
        cin >> t >> l >> r;
        if (t == 2){
            upd(1,n+1,l,1,r);
            continue;
        }
        int x,y;
        cin >> x;
        y = que(1,n+1,l,r+1,1,x);
        if (y >= 2) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}