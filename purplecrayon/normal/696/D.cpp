#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e2+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 95542721, MAXK = 1e2+10,  MAXA = 10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

int n;
ll x, a[MAXN];
string s[MAXN];

const int K = 26;
struct Vertex {
    int next[K];
    bool leaf = false;
    ll leaf_val = 0, link_val = -1;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];
    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};
vector<Vertex> t(1);
int add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
    return v;
}
int go(int v, char ch);
int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}
int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 
ll link_val(int v) {
    if (t[v].link_val != -1) return t[v].link_val;
    t[v].link_val = t[v].leaf_val;
    if (v) t[v].link_val += link_val(get_link(v));
    return t[v].link_val;
}
struct mat {
    vector<vector<ll>> a;
    mat operator*(const mat& m) const {
        assert(sz(a[0])==sz(m.a));
        mat res; res.a.assign(sz(a), vector<ll>(sz(m.a[0]), -INF));
        for (int i = 0; i < sz(a); i++){
        	for (int k = 0; k < sz(a[0]); k++){
            	for (int j = 0; j < sz(m.a[0]); j++){
                    res.a[i][j] = max(res.a[i][j], a[i][k]+m.a[k][j]);
                }
            }
        }
        return res;
    }
};
mat po(mat m, ll n){
    int siz=sz(m.a);
    mat res; res.a.assign(siz, vector<ll>(siz, -INF));
    for (int i = 0; i < siz; i++) res.a[i][i] = 0ll;
    for (; n; n /= 2, m=m*m)
        if (n&1) res = res*m;
    return res;
}
void solve(){
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> s[i]; int c = add_string(s[i]);
        t[c].leaf_val += a[i];
    }

    //start at 0th vertex
    //find maximum length path in a graph
    mat m; m.a.assign(sz(t), vector<ll>(sz(t), -INF));
    for (int i = 0; i < sz(t); i++) {
        for (int j = 0; j < 26; j++) {
            int nxt = go(i, j+'a');
            m.a[i][nxt] = max(m.a[i][nxt], link_val(nxt));
        }
    }
    mat r = po(m, x);
    ll ans=0;
    for (int i = 0; i < sz(t); i++) {
        ans = max(ans, r.a[0][i]);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}