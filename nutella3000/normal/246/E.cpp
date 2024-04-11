#include <bits/stdc++.h>
 
using namespace std;
 
#define aidar asadulin
 
//#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
#define ld long double
 
const int inf = 1e9;
const int max_n = 1e5 + 2;
 
int n;
int s[max_n];
vector<int> gr[max_n];
vector<int> roots;
 
int sz[max_n], deep[max_n];
 
map<int, set<int>> a[max_n];
int res[max_n];
vector<pii> req[max_n];
 
void dfs(int v) {
    sz[v] = 1;
 

    int m_to = (sz(gr[v]) ? gr[v][0] : -1);
 
    for(int i : gr[v]) {
        deep[i] = deep[v] + 1;
        dfs(i);
        
        if (sz[v] < sz[i]) {
            swap(a[v], a[i]);
        }

        for(auto k1 : a[i]) {
            for(auto k2 : k1.se) {
                a[v][k1.fi].emplace(k2);
            }
        }


        sz[v] += sz[i];
    }
    
 /*
    a[v] = a[m_to]; 
 
    for(int i : gr[v]) {
        if (i == m_to) continue;
 
        for(auto k1 : a[i]) {
            for(auto k2 : k1.se) {
                a[v][k1.fi].emplace(k2);
            }
        }
    }*/
    a[v][deep[v]].emplace(s[v]);
 
 
    for(auto i : req[v]) {
        res[i.se] = sz(a[v][i.fi + deep[v]]);
    }
}
 
void solve() {
    cin >> n;
 
    map<string, int> converter;
 
    for(int i = 1;i <= n;i++) {
        string temp;
        int par;
        cin >> temp >> par;
 
        if (!converter.count(temp)) converter[temp] = sz(converter);
        s[i] = converter[temp];
 
        if (par == 0) {
            roots.emplace_back(i);
            continue;
        }
        gr[par].emplace_back(i);
    }
 
    int q;
    cin >> q;
    for(int i = 0;i < q;i++) {
        int v, k;
        cin >> v >> k;
        req[v].emplace_back(k, i);
    }
 
    for(int i : roots) {
        dfs(i);
    }
 
    for(int i = 0;i < q;i++)
        cout << res[i] << endl;
}
 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    solve();
}