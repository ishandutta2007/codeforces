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
const long long int N = 3e5+20,mod = 1e9+7,inf = 1e9+10,sq = 400;
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
int seg[N*4];
set<int> st[40];
void ref(int l,int r,int v){
    seg[v] = 0;
    if (r-l == 1) return;
    int m = (l+r) >> 1,u = (v << 1);
    ref(l,m,u);
    ref(m,r,u|1);
}

void upd(int l,int r,int p,int v){
    if (r-l == 1){
        seg[v] = 1;
        return;
    }
    int m = (l+r) >> 1,u = (v << 1);
    if (p < m) upd(l,m,p,u);
    else upd(m,r,p,u|1);
    seg[v] = seg[u]+seg[u|1];
}

int que(int l,int r,int s,int e,int v){
    if (l >= s && e >= r) return seg[v];
    if (l >= e || s >= r) return 0;
    int m = (l+r) >> 1,u = (v << 1);
    return que(l,m,s,e,u)+que(m,r,s,e,u|1);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        string s,t;
        int n;
        cin >> n >> s >> t;
        ll ans = inf*inf,cost = 0;
        rep(i,0,n) st[s[i]-'a'].insert(i);
        rep(i,0,n){
            if (cost >= ans) break;
            rep(j,0,(t[i]-'a')){
                if (!st[j].empty()){
                    int ind = *(st[j].begin());
                    int cnt = que(0,n,ind,n,1);
                    ans = min(ans,cost+ind-i+cnt);
                }
            }
            if (st[t[i]-'a'].empty()) break;
            int ind = *(st[t[i]-'a'].begin());
            cost += ind-i+que(0,n,ind,n,1);
            upd(0,n,ind,1);
            st[t[i]-'a'].erase(st[t[i]-'a'].begin());
        }
        ref(0,n,1);
        rep(i,0,40) st[i].clear();
        if (ans < inf*inf) cout << ans << endl;
        else cout << -1 << endl;
    }
}