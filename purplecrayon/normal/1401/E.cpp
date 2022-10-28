#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 2e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, INF = 1e9+10, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

ll n, m, ans = 1, t[4*MAXN];
map<ll, int> cmpy;
vector<array<ll, 3>> h, v;
vector<array<ll, 4>> ev;

ll qry(int v, int tl, int tr, int l, int r){
    if (r < tl || l > tr) return 0;
    if (tl >= l && tr <= r) return t[v];
    int tm = (tl+tr)/2;
    return qry(2*v, tl, tm, l, r)+qry(2*v+1, tm+1, tr, l, r);
}
void upd(int v, int tl, int tr, int pos, int add){
    if (pos < tl || pos > tr) return;
    if (tl == tr) { t[v] += add; return; }
    int tm = (tl+tr)/2;
    upd(2*v, tl, tm, pos, add), upd(2*v+1, tm+1, tr, pos, add);
    t[v] = t[2*v]+t[2*v+1];
}
void solve(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        ll y, l, r; cin >> y >> l >> r; ans += (l==0 && r==1000000);
        h.push_back(array<ll, 3>{y, l, r}); cmpy[y]++;
    }
    for (int i = 0; i < m; i++){
        ll x, l, r; cin >> x >> l >> r; ans += (l==0 && r==1000000);
        v.push_back(array<ll, 3>{x, l, r}); cmpy[l]++, cmpy[r]++;
    }
    int ccmp = 0; for (auto& it : cmpy) it.second = ccmp++;
    for (int i = 0; i < n; i++){
        ll l = h[i][1], r = h[i][2];
        ev.push_back({l, 0, i});
        ev.push_back({r, 2, i});
    }
    for (int i = 0; i < m; i++){
        ll x= v[i][0];
        ev.push_back({x, 1, i});
    }
    sort(ev.begin(), ev.end());
    memset(t, 0, sizeof(t));
    for (auto e : ev){
        // if (e[1] == 0 || e[1] == 2) cout << "H: ";
        // else cout << "V: ";
        // cout << e[2] << " ";
        if (e[1]==0){ //starting hori
            ll y = h[e[2]][0];
            int yy = cmpy[y];
            upd(1, 0, ccmp, yy, 1);
            // cout << "ADDING: " << yy << "\n";
        } else if (e[1]==1){ //qry vert
            ll l = v[e[2]][1], r = v[e[2]][2];
            int cl = cmpy[l], cr = cmpy[r];
            ll c = qry(1, 0, ccmp, cl, cr); //cout << c;
            ans += c;
            // cout << "QUERYING: " << cl << " " << cr << " " << c << "\n";
        } else if (e[1]==2){ //ending hori
            ll y = h[e[2]][0];
            int yy = cmpy[y];
            upd(1, 0, ccmp, yy, -1);
            // cout << "REMOVING: " << yy << "\n";
        }
    }
    cout << ans;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}