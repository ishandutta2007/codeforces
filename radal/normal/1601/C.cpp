#include <bits/stdc++.h>
#pragma GCC optimize("O3")
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
typedef long double ld;
typedef pair<int,int> pll;
const long long int N = 1e6+20,mod = 1e9+7,inf = 1e9+10,sq = 32000;
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

int a[N],b[N];
int n;
int fen[N*2];
int seg[N*4],lz[N*4];

void upd(int l){
    for (; l <= n; l |= (l+1))
        fen[l]++;
}

int q(int r){
    int ans = 0;
    for (; r >= 0; r = (r&(r+1))-1) 
        ans += fen[r];
    return ans;
}

void build(int l,int r,int v = 1){
    lz[v] = 0;
    seg[v] = 0;
    if (r-l == 1) return;
    int m = (l+r) >> 1,u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
}

void upd(int l,int r,int s,int e,int x,int v = 1){
    if (s >= e || s >= r || l >= e) return;
    if (s <= l && r <= e){
        lz[v] += x;
        seg[v] += x;
        return;
    }
    int u = (v << 1),m = (l+r) >> 1;
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
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int m;
        cin >> n >> m;
        vector<pll> ve;
        rep(i,0,n){
            cin >> a[i];
            ve.pb({a[i],i});
            fen[i] = 0;
        }
        rep(i,0,m)
            cin >> b[i];
        sort(b,b+m);
        sort(ve.begin(),ve.end());
        ll ans = 0;
        repr(i,n-1,0){
            int ind = lower_bound(ve.begin(),ve.end(),make_pair(a[i],0))-ve.begin();
            ans += q(ind-1);
            upd(ind);
        }
        rep(i,0,n){
            upd(0,n+1,i+1,n+1,1);
        }
        int p1 = 0,p2 = 0;
        rep(i,0,m){
            while (p1 < n && ve[p1].X <= b[i]){
                upd(0,n+1,ve[p1].Y+1,n+1,-1);
                p1++;
            }
            while (p2 < n && ve[p2].X < b[i]){
                upd(0,n+1,0,ve[p2].Y+1,1);
                p2++;
            }
            ans += seg[1];
        }
        cout << ans << endl;
        build(0,n+1);
    }
    return 0;
}