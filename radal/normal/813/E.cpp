#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2")
//#pragma GCC optimize("unroll-loops,O3")
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
constexpr int N = 1e5+5,mod = 1e9+7,inf = 1e9+10;
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
vector<int> ind[N],seg[N*4];
int a[N],b[N];
void build(int l,int r,int v = 1){
    if (r-l == 1){
        seg[v].pb(b[l]);
        return;
    }
    int u = (v << 1),m = (l+r) >> 1,p = 0,q = 0;
    seg[v].reserve(r-l);
    build(l,m,u);
    build(m,r,u|1);
    while (p < m-l || q < r-m){
        if (p == m-l || (q < r-m && seg[u|1][q] <= seg[u][p])){
            seg[v].pb(seg[u|1][q]);
            q++;
        }
        else{
            seg[v].pb(seg[u][p]);
            p++;
        }
    }
}
int que(int l,int r,int s,int e,int v = 1){
    if (s >= r || l >= e) return 0;
    if (s <= l && r <= e){
        return lower_bound(all(seg[v]),s)-seg[v].begin();
    }
    int m = (l+r) >> 1,u = (v << 1);
    return que(l,m,s,e,u)+que(m,r,s,e,u|1);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> n >> k;
    rep(i,0,n){
        cin >> a[i];
        ind[a[i]].pb(i);
        if ((int)ind[a[i]].size() <= k) b[i] = -1;
        else b[i] = ind[a[i]][ind[a[i]].size()-k-1];
    }
    build(0,n);
    int last = 0,q;
    cin >> q;
    while (q--){
        int x,y,l,r;
        cin >> x >> y;
        l = (x+last)%n+1;
        r = (y+last)%n+1;
        if (l > r) swap(l,r);
        l--;
        last = que(0,n,l,r);
        cout << last << endl;
    }
    return 0;
}