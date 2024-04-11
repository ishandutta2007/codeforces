#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()

typedef long long ll;
const int MAXN = (1 << 17)+10, MAXM = 1e5+10, MAXL = 18;

int n, m, nl, depth[4*MAXN];
ll a[MAXN], t[4*MAXN];

void bld(int v, int tl, int tr){
    if (tl == tr){
        t[v] = a[tl], depth[v] = 0;
    } else {
        int tm = (tl+tr)/2;
        bld(2*v, tl, tm); bld(2*v+1, tm+1, tr);
        depth[v] = depth[2*v]^1;
        if (depth[v]&1) t[v] = t[2*v]|t[2*v+1];
        else t[v] = t[2*v]^t[2*v+1];
    }
}
void upd(int v, int tl, int tr, int pos, ll nv){
    if (pos < tl || pos > tr) return;
    if (tl == tr) { t[v] = nv; return; }
    int tm = (tl+tr)/2;
    upd(2*v, tl, tm, pos, nv), upd(2*v+1, tm+1, tr, pos, nv);
    if (depth[v]&1) t[v] = t[2*v]|t[2*v+1];
    else t[v] = t[2*v]^t[2*v+1];
}
void solve(){
    cin >> nl >> m; n = (1 << nl);
    for (int i = 0; i < n; i++) cin >> a[i];
    bld(1, 0, n-1);
    while (m--){
        int pos; ll nv; cin >> pos >> nv, --pos;
        upd(1, 0, n-1, pos, nv); cout << t[1] << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--) solve();
}