#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O3")
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
constexpr int N = 3e3+10,mod = 1e9+7,inf = 1e9+10;
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
int r,c,n,k;
vector<pll> ve;
int seg[N*4][2]; // calc sum
int pre[N*4][15],suf[N*4][15];
void upd(int l,int r,int p,int x,int v = 1){
    if (r-l == 1){
        seg[v][1] += x;
        if (seg[v][1] >= k) seg[v][0] = 1;
        else seg[v][0] = 0;
        int lim = min(k,seg[v][1])+1;
        rep(i,0,lim){
            pre[v][i] = 1;
            suf[v][i] = 1;
        }
        if (x == -1){
            rep(i,lim,k+1){
                pre[v][i] = 0;
                suf[v][i] = 0;
            }
        }
        return;
    }
    int m = (l+r) >> 1,u = (v << 1),w = u|1;
    if (p < m) upd(l,m,p,x,u);
    else upd(m,r,p,x,w);
    seg[v][1] = seg[u][1]+seg[w][1];
    seg[v][0] = seg[u][0]+seg[w][0];
    rep(i,0,k+1){
        if (i <= seg[u][1])
            pre[v][i] = pre[u][i]+r-m;
        else
            pre[v][i] = pre[u][i]+pre[w][i-seg[u][1]];
        if (i <= seg[w][1])
            suf[v][i] = suf[w][i]+m-l;
        else
            suf[v][i] = suf[w][i]+suf[u][i-seg[w][1]];
        seg[v][0] += (suf[u][i]-suf[u][i+1])*pre[w][k-i];
    }
}
void rst(int l,int r,int v){
    seg[v][0] = 0;
    seg[v][1] = 0;
    pre[v][0] = r-l;
    suf[v][0] = r-l;
    rep(i,1,k+1){
        pre[v][i] = 0;
        suf[v][i] = 0;
    }
    if (r-l == 1) return;
    int m = (l+r) >> 1,u = (v << 1);
    rst(l,m,u);
    rst(m,r,u|1);
}
inline bool cmp(pll i,pll j){
    if (i.X != j.X) return (i.X < j.X);
    if (i.X&1) 
        return (i.Y < j.Y);
    return (i.Y > j.Y);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> r >> c >> n >> k;
    rep(i,0,n){
        int x,y;
        cin >> x >> y;
        y--;
        ve.pb({x,y});
    }
    sort(all(ve));
    int po = 0,po2 = 0;
    ll ans = 0;
    rst(0,c,1);
    rep(i,1,r+1){
        while (po < n && ve[po].X < i){
            upd(0,c,ve[po].Y,-1);
            po++;
        }
        if (po == n) break;
        if (i&1){
            po2 = po;
            rep(j,i,r+1){
                while (po2 < n && ve[po2].X <= j){
                    upd(0,c,ve[po2].Y,1);
                    po2++;
                }
                if (po2 == n){
                   // debug(i);
                 //   debug(j);
                  //  debug(seg[1][0]);
                    ans += seg[1][0]*(r-j+1);
                    break;
                }
                //debug(i);
               // debug(j);
              //  debug(seg[1][0]);
                ans += seg[1][0];
            }
            continue;
        }
        po2 = n;
        repr(j,r,i+1){
        //    debug(i);
          //  debug(j);
            //debug(seg[1][0]);
            ans += seg[1][0];
            while (po2 > 0 && ve[po2-1].X >= j){
                upd(0,c,ve[po2-1].Y,-1);
                po2--;
            }
            if (po2 == 0 || ve[po2-1].X < i) break;
        }
        ans += seg[1][0];
    }
    cout << ans;
    return 0;
}