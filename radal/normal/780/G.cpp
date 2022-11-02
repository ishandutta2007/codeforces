#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
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
constexpr int N = 1e5+20,mod = 1e9+7 ,inf = 1e9+10,maxm = (1 << 10)+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    } 
    return z;
}
set<pair<pll,int>> seg[N*4];
vector<pair<pll,pll>> ve;
void ins(int l,int r,int p,int x,int t,int v = 1){
    seg[v].insert({{x,t},p});
    if (r-l == 1) return;
    int m = (l+r) >> 1,u = (v << 1);
    if (p < m) ins(l,m,p,x,t,u);
    else ins(m,r,p,x,t,u|1);
}

void era(int l,int r,pair<pll,int> p,int v = 1){
    seg[v].erase(p);
    if (r-l == 1) return;
    int m = (l+r) >> 1,u = (v << 1);
    if(p.Y < m) era(l,m,p,u);
    else era(m,r,p,u|1);
}
pair<pll,int> que(int l,int r,int s,int e,int v = 1){
    if (s <= l && r <= e){
        if (seg[v].size()) return *(seg[v].begin());
        return {{inf*2,0},l};
    }
    if (l >= e || s >= r) return {{inf*2,0},l};
    int m = (l+r) >> 1,u = (v << 1);
    return min(que(l,m,s,e,u),que(m,r,s,e,u|1));
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,h,w;
    cin >> h >> w >> n;
    rep(i,0,w){
       ins(0,w,i,h+1,1);
    }
    rep(i,0,n){
        int u,l,r,s;
        cin >> u >> l >> r >> s;
        l--;
        ve.pb({{u,l},{r,s}});
    }
    sort(all(ve));
    reverse(all(ve));
    rep(i,0,n){
        int s = ve[i].Y.Y,u = ve[i].X.X,l = ve[i].X.Y,r = ve[i].Y.X;
        int sum = 0;
        while (1){
            auto p = que(0,w,l,r);
            if (p.X.X-u > s) break;
            era(0,w,p);
            sum = mkay(sum,p.X.Y);
        }
        if (!sum) continue;
        if (l && r < w){
            ins(0,w,l-1,u,sum);
            ins(0,w,r,u,sum);
        }
        else if (l)
            ins(0,w,l-1,u,mkay(sum,sum));
        else
            ins(0,w,r,u,mkay(sum,sum));
    }
    int ans = 0,t = 0;
    rep(i,0,w){
        while (1){
            auto p = que(0,w,i,i+1);
            if (p.X.X > h+1) break;
            ans = mkay(ans,p.X.Y);
            era(0,w,p);
            t++;
        }
    }
    cout << ans;
}