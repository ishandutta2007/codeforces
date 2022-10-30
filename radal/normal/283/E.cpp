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
const long long int N = 1e5+20,mod = 1e9+7,inf = 1e9,sq = 4e7;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int seg[4*N],lz[4*N];
int a[N];
vector<int> ve[N],ve2[N];
pll b[N];

void upd(int l,int r,int s,int e,int v){
    if (l >= s && e >= r){
        seg[v] = r-l-seg[v];
        lz[v] = 1-lz[v];
        return;
    }
    if (l >= e || s >= r) return;
    int m = (l+r) >> 1,u = (v << 1);
    if (lz[v]){
        lz[v] = 0;
        lz[u] = 1-lz[u];
        lz[u|1] = 1-lz[u|1];
        seg[u] = m-l-seg[u];
        seg[u|1] = r-m-seg[u|1];
    }
    upd(l,m,s,e,u);
    upd(m,r,s,e,u|1);
    seg[v] = seg[u]+seg[u|1];
}

int que(int l,int r,int s,int e,int v = 1){
    if (l >= s && e >= r){
        return seg[v];
    }
    if (l >= e || s >= r || s >= e) return 0;
    int m = (l+r) >> 1,u = (v << 1);
    if (lz[v]){
        lz[v] = 0;
        lz[u] = 1-lz[u];
        lz[u|1] = 1-lz[u|1];
        seg[u] = m-l-seg[u];
        seg[u|1] = r-m-seg[u|1];
    }
    return que(l,m,s,e,u)+que(m,r,s,e,u|1);
}

int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin >> n >> q;
    rep(i,0,n)
        cin >> a[i];
    sort(a,a+n);
    rep(i,0,q){
        int x,y;
        cin >> x >> y;
        if (x > a[n-1]){
            q--;
            i--;
            continue;
        }
        int l = lower_bound(a,a+n,x)-a,r = upper_bound(a,a+n,y)-a;
        ve[l].pb(r);
        ve2[r].pb(l);
    }
    ll ans = 0;
    rep(i,0,n){
        for (int r : ve[i]){
            upd(0,n,i,r,1);
        }
        for (int l : ve2[i]){
            upd(0,n,l,i,1);
        }
        int d = que(0,n,i+1,n,1)+i-que(0,n,0,i,1);
        ans += 1ll*d*(d-1)/2;
    }
    cout << 1ll*n*(n-1)*(n-2)/6-ans;

    return 0;
}