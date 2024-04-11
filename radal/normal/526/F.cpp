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
constexpr int N = 3e5+20,mod = 1e9+7,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k,int p){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%p;
        a = 1ll*a*a%p;
        k >>= 1;
    } 
    return z; 
}
int a[N],n,lz[N*4];
pll seg[N*4];
inline void pass(int v){
    if(!lz[v]) return;
    int u = (v << 1);
    lz[u] += lz[v];
    lz[u|1] += lz[v];
    seg[u].X += lz[v];
    seg[u|1].X += lz[v];
    lz[v] = 0;
}

void upd(int l,int r,int p,int x,int v){
    if (r-l == 1){
        seg[v] = {x,1};
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    pass(v);
    if (p < m) upd(l,m,p,x,u);
    else upd(m,r,p,x,u|1);
    if (seg[u].X == seg[u|1].X) seg[v] = {seg[u].X,seg[u].Y+seg[u|1].Y};
    else seg[v] = max(seg[u],seg[u|1]);
}

void upd2(int l,int r,int s,int e,int x,int v){
    if (l >= e || s >= e || s >= r) return;
    if (s <= l && r <= e){
        lz[v] += x;
        seg[v].X += x;
        return;
    }
    pass(v);
    int u = (v << 1),m = (l+r) >> 1;
    upd2(l,m,s,e,x,u);
    upd2(m,r,s,e,x,u|1);
    if (seg[u].X == seg[u|1].X) seg[v] = {seg[u].X,seg[u].Y+seg[u|1].Y};
    else seg[v] = max(seg[u],seg[u|1]);
}
pll que(int l,int r,int s,int e,int v = 1){
    if (l >= e || s >= e || s >= r) return {-inf,1};
    if (s <= l && r <= e) return seg[v];
    pass(v);
    int m = (l+r) >> 1,u = (v << 1);
    pll p1 = que(l,m,s,e,u),p2 = que(m,r,s,e,u|1);
    if (p1.X == p2.X) return {p1.X,p1.Y+p2.Y};
    return max(p1,p2);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i,0,n){
        int r,c;
        cin >> r >> c;
        r--;
        a[r] = c;
    }
    stack<int> st1,st2;
    ll ans = 0;
    rep(i,0,n){
        upd2(0,n,0,i,1,1);
        upd(0,n,i,0,1);
        int r = i;
        while (!st1.empty() && a[st1.top()] < a[i]){
            int l,v = a[st1.top()];
            st1.pop();
            if (!st1.empty()) l = st1.top()+1;
            else l = 0;
            upd2(0,n,l,r,-a[i]+v,1);
            r = l;
        }
        r = i;
        while (!st2.empty() && a[st2.top()] > a[i]){
            int l,v = a[st2.top()];
            st2.pop();
            if (!st2.empty()) l = st2.top()+1;
            else l = 0;
            upd2(0,n,l,r,a[i]-v,1);
            r = l;
        }
        st1.push(i);
        st2.push(i);
        ans += que(0,n,0,i+1,1).Y;
    }
    cout << ans;
    return 0;
}