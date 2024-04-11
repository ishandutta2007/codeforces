#include <bits/stdc++.h>
 
using namespace std;
 
//#define aidar asadulin
 
//#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define pip pair<int, pii>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double
 
const int inf = 1e9 + 7;
const int max_n = 5e5 + 3;
 
int n, k;
 
map<pii, vector<pii>> edge;
vector<int> gr[max_n];
int c[max_n];
int col[max_n];
bool bad[max_n];
int T = 2;
 
bool dfs(int v) {
    if (col[v] != 0) {
        if (col[v] != T) return true;
        return false;
    }
    col[v] = T;
 
    T = (T ^ 1);
    for(int i : gr[v]) {
        if (dfs(i)) return true;
    }
 
    T = (T ^ 1);
 
    return false;
}
 
void scan() {
    int m;
    cin >> n >> m >> k;
    for(int i = 0;i < n;i++) {
        cin >> c[i];
        c[i]--;
    }
 
    for(int i = 0;i < m;i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        if (c[v1] != c[v2]) {
            if (c[v1] > c[v2]) swap(v1, v2);
            edge[mp(c[v1], c[v2])].emplace_back(v1, v2);
        }else {
            gr[v1].emplace_back(v2);
            gr[v2].emplace_back(v1);
        }
    }
 
    for(int i = 0;i < n;i++) {
        if (col[i] == 0 && !bad[c[i]]) {
            if (dfs(i)) {
                bad[c[i]] = true;
            }
            T += 2;
        }
    }
}
 
struct dsu {
    map<int, int> p;
    map<int, int> sz;
 
    dsu() {}
 
    int get(int v) {
        int s = v;
        while(p.count(v) && p[v] != v) v = p[v];
 
        while(s != v) {
            int t = p[s];
            p[s] = v;
            s = t;
        }
        return v;
    }
 
    void merge(int v1, int v2) {
        v1 = get(v1);
        v2 = get(v2);
 
        if (!sz.count(v1)) sz[v1] = 1;
        if (!sz.count(v2)) sz[v2] = 1;
 
        if (sz[v1] > sz[v2]) swap(v1, v2);
 
        p[get(v1)] = get(v2);
 
        if (sz[v1] == sz[v2]) sz[v2]++;
    }
};
 
void solve() {
    scan();
 
    ll res = (ll)k * (k - 1) / 2;
 
    ll temp = 0;
    for(int i = 0;i < k;i++)
        temp += bad[i];
 
    //cout << res << " " << temp << endl;
    res -= temp * (k - temp) + temp * (temp - 1) / 2;
 
    for(auto req : edge) {
        if (bad[req.fi.fi] || bad[req.fi.se]) continue;
 
        dsu comps = dsu();
 
        for(pii v : req.se) { 
            v.fi = col[v.fi];
            v.se = col[v.se];
            comps.merge(v.fi, v.se ^ 1);
            comps.merge(v.fi ^ 1, v.se);
        }
 
        for(auto& i : comps.p) {
            int num = comps.get(i.se);
            if (comps.p.count(i.fi ^ 1) && comps.get(i.fi ^ 1) == num) {
                res--;
                break;
            }
        }
    }    
 
    cout << res;
}
 
 
 
 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    solve();
}