#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
#pragma GCC optimize("unroll-loops,O2")
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
constexpr int N = 2e5+20,mod = 1e9+7,inf = 1e9+10,len = 7;
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
int n,a[N];
int seg[N*4][2][2];
int cl[N],cr[N];
vector<int> ve;
void build(int l,int r,int v = 1){
    if (r-l == 1){
        if (!l) return;
        seg[v][0][0] = 0;
        seg[v][0][1] = 0;
        if (cr[l]){
            seg[v][1][0] = 1;
            seg[v][1][1] = 1;
        }
        return;
    }
    int m = (l+r) >> 1, u = (v << 1);
    build(l,m,u);
    build(m,r,u|1);
    seg[v][0][0] = 0;
    seg[v][0][1] = 0;
    if (!seg[u|1][1][1]){
        seg[v][1][0] = seg[u][1][0];
        seg[v][1][1] = seg[u][1][1];
        return;
    }
    if (seg[u][1][1]) seg[v][1][0] = min(seg[u|1][1][0],seg[u|1][1][1]+seg[u][1][0]);
    else seg[v][1][0] = seg[u|1][1][0];
    seg[v][1][1] = seg[u|1][1][1]+seg[u][1][1];
}
void upd(int l,int r,int p,int x,int v = 1){ // L R L/R
    if (r-l == 1){
        if (x == 0){
            seg[v][0][0] = 1;
            seg[v][0][1] = 1;
            seg[v][1][0] = 0;
            seg[v][1][1] = 0;
            return;
        }
        if (x == 1){
            seg[v][0][0] = 0;
            seg[v][0][1] = 0;
            seg[v][1][0] = 1;
            seg[v][1][1] = 1;
            return;
        }
        seg[v][0][0] = 1;
        seg[v][0][1] = 1;
        seg[v][1][0] = 1;
        seg[v][1][1] = 1;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    if (p < m) upd(l,m,p,x,u);
    else upd(m,r,p,x,u|1);
    if (!seg[u][0][0] && !seg[u][1][1]){
        rep(j,0,2)
            rep(k,0,2)
             seg[v][j][k] = seg[u|1][j][k];
        return;
    }
    if (!seg[u|1][0][0] && !seg[u|1][1][1]){
        rep(j,0,2)
            rep(k,0,2)
                seg[v][j][k] = seg[u][j][k];
        return;
    }
    if (!seg[u|1][0][0]){
        seg[v][0][0] = seg[u][0][0];
        seg[v][0][1] = seg[u][0][1];
        if (!seg[u][0][0]){
            seg[v][1][0] = min(seg[u|1][1][1]+seg[u][1][0],seg[u|1][1][0]);
            seg[v][1][1] = seg[u|1][1][1]+seg[u][1][1];
            return;
        }
        if (!seg[u][1][1]){
            seg[v][1][1] = min(seg[u|1][1][0]+seg[u][0][1],seg[u|1][1][1]);
            seg[v][1][0] = seg[u|1][1][0]+seg[u][0][0];
            return;
        }
        seg[v][1][0] = min(seg[u|1][1][1]+seg[u][1][0],seg[u|1][1][0]+seg[u][0][0]);
        seg[v][1][1] = min(seg[u|1][1][1]+seg[u][1][1],seg[u|1][1][0]+seg[u][0][1]);
        return;
    }
    if (!seg[u|1][1][1]){
        seg[v][1][0] = seg[u][1][0];
        seg[v][1][1] = seg[u][1][1];
        if (!seg[u][0][0]){
            seg[v][0][0] = min(seg[u|1][0][1]+seg[u][1][0],seg[u|1][0][0]);
            seg[v][0][1] = seg[u|1][0][1]+seg[u][1][1];
            return;
        }
        if (!seg[u][1][1]){
            seg[v][0][1] = min(seg[u|1][0][0]+seg[u][0][1],seg[u|1][0][1]);
            seg[v][0][0] = seg[u|1][0][0]+seg[u][0][0];
            return;
        }
        seg[v][0][0] = min(seg[u|1][0][1]+seg[u][1][0],seg[u|1][0][0]+seg[u][0][0]);
        seg[v][0][1] = min(seg[u|1][0][1]+seg[u][1][1],seg[u|1][0][0]+seg[u][0][1]);
        return;
    }
    if (!seg[u][0][0]){
        seg[v][0][0] = min(seg[u|1][0][0],seg[u|1][0][1]+seg[u][1][0]);
        seg[v][0][1] = seg[u|1][0][1]+seg[u][1][1];
        seg[v][1][0] = min(seg[u|1][1][0],seg[u|1][1][1]+seg[u][1][0]);
        seg[v][1][1] = seg[u|1][1][1]+seg[u][1][1];
        return;
    }
    if (!seg[u][1][1]){
        seg[v][0][1] = min(seg[u|1][0][1],seg[u|1][0][0]+seg[u][0][1]);
        seg[v][0][0] = seg[u|1][0][0]+seg[u][0][0];
        seg[v][1][1] = min(seg[u|1][1][1],seg[u|1][1][0]+seg[u][0][1]);
        seg[v][1][0] = seg[u|1][1][0]+seg[u][0][0];
        return;
    }
    seg[v][0][0] = min(seg[u|1][0][0]+seg[u][0][0],seg[u|1][0][1]+seg[u][1][0]);
    seg[v][1][0] = min(seg[u|1][1][0]+seg[u][0][0],seg[u|1][1][1]+seg[u][1][0]);
    seg[v][0][1] = min(seg[u|1][0][0]+seg[u][0][1],seg[u|1][0][1]+seg[u][1][1]);
    seg[v][1][1] = min(seg[u|1][1][0]+seg[u][0][1],seg[u|1][1][1]+seg[u][1][1]);
}
void que(int l,int r,int s,int e,int v = 1){
    if (s >= r || l >= e) return;
    if (s <= l && r <= e){
        ve.pb(v);
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    que(m,r,s,e,u|1);
    que(l,m,s,e,u);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i,1,n+1){
        cin >> a[i];
        cr[a[i]]++;
    }
    cr[0]++;
    cl[0]++;
    build(0,n+1);
    ll ans = 0;
    rep(i,1,n+1){
        if (i > 1 && a[i-1]){
            cl[a[i-1]]++;
            if (cr[a[i-1]] && cl[a[i-1]] == 1) upd(0,n+1,a[i-1],2);
            else if (!cr[a[i-1]]) upd(0,n+1,a[i-1],0);
        }
        cr[a[i]]--;
        if (!a[i]) continue;
        int cur[2][2],tmp[2][2];
        cur[0][0] = 0;
        cur[0][1] = 0;
        cur[1][0] = 0;
        cur[1][1] = 0;
        que(0,n+1,0,a[i]);
        int sz = ve.size();
        rep(g,0,sz){
            int v = ve[g];
            if (!seg[v][0][0] && !seg[v][1][1]) continue;
            if (!g){
                rep(j,0,2)
                    rep(k,0,2)
                        cur[j][k] = seg[v][j][k];
                continue;
            }
            if (!cur[0][0]  && !cur[1][1]){
                rep(j,0,2)
                    rep(k,0,2)
                        cur[j][k] = seg[v][j][k];
                continue;
            }
            if (!cur[0][0]){ // R
                tmp[0][0] = seg[v][0][0];
                tmp[0][1] = seg[v][0][1];
                if (!seg[v][0][0]){
                    tmp[1][0] = min(cur[1][0],cur[1][1]+seg[v][1][0]);
                    tmp[1][1] = cur[1][1]+seg[v][1][1];
                }
                else if (!seg[v][1][1]){
                    tmp[1][0] = cur[1][0]+seg[v][0][0];
                    tmp[1][1] = min(cur[1][1],cur[1][0]+seg[v][0][1]);
                }
                else{
                    tmp[1][0] = min(cur[1][0]+seg[v][0][0],cur[1][1]+seg[v][1][0]);
                    tmp[1][1] = min(cur[1][0]+seg[v][0][1],cur[1][1]+seg[v][1][1]);
                }
            }
            else if (!cur[1][1]){ // L
                tmp[1][0] = seg[v][1][0];
                tmp[1][1] = seg[v][1][1];
                if (!seg[v][0][0]){
                    tmp[0][0] = min(cur[0][0],cur[0][1]+seg[v][1][0]);
                    tmp[0][1] = cur[0][1]+seg[v][1][1];
                }
                else if (!seg[v][1][1]){
                    tmp[0][1] = min(cur[0][1],cur[0][0]+seg[v][0][1]);
                    tmp[0][0] = cur[0][0]+seg[v][0][0];
                }
                else{
                    tmp[0][0] = min(cur[0][0]+seg[v][0][0],cur[0][1]+seg[v][1][0]);
                    tmp[0][1] = min(cur[0][0]+seg[v][0][1],cur[0][1]+seg[v][1][1]);
                }
            }
            else{
                if (!seg[v][1][1]){
                    tmp[0][0] = cur[0][0]+seg[v][0][0];
                    tmp[1][0] = cur[1][0]+seg[v][0][0];
                    tmp[0][1] = min(cur[0][1],cur[0][0]+seg[v][0][1]);
                    tmp[1][1] = min(cur[1][1],cur[1][0]+seg[v][0][1]);
                }
                else if (!seg[v][0][0]){
                    tmp[0][0] = min(cur[0][0],cur[0][1]+seg[v][1][0]);
                    tmp[1][0] = min(cur[1][0],cur[1][1]+seg[v][1][0]);
                    tmp[0][1] = cur[0][1]+seg[v][1][1];
                    tmp[1][1] = cur[1][1]+seg[v][1][1];
                }  
                else{
                    tmp[0][0] = min(cur[0][0]+seg[v][0][0],cur[0][1]+seg[v][1][0]);
                    tmp[0][1] = min(cur[0][0]+seg[v][0][1],cur[0][1]+seg[v][1][1]);
                    tmp[1][0] = min(cur[1][0]+seg[v][0][0],cur[1][1]+seg[v][1][0]);
                    tmp[1][1] = min(cur[1][0]+seg[v][0][1],cur[1][1]+seg[v][1][1]);
                }
            }
            rep(j,0,2)
                rep(k,0,2)
                    cur[j][k] = tmp[j][k];
        }
        ve.clear();
        ans += 1+min({cur[0][0],cur[0][1],cur[1][0],cur[1][1]});
    }
    cout << ans;
}