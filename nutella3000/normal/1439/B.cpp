#include <bits/stdc++.h>
 
using namespace std;


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define aidar asadulin
 
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
#define ld double
 
const ll inf = 1e9 + 7;
const int max_n = 1e5 + 3;

set<int> gr[max_n];
vector<int> gr1[max_n];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0;i < n;i++) {
        gr[i].clear();
        gr1[i].clear();
    }

    vector<int> deg(n);

    auto sorti = [&deg](int v1, int v2) {
        if (deg[v1] == deg[v2]) return v1 < v2;
        return deg[v1] < deg[v2];
    };

    set<int, decltype(sorti)> a(sorti);

    for(int i = 0;i < m;i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        gr[v1].emplace(v2);
        gr[v2].emplace(v1);
        gr1[v1].emplace_back(v2);
        gr1[v2].emplace_back(v1);
        deg[v1]++;
        deg[v2]++;
    }
    for(int i = 0;i < n;i++)
        sort(all(gr1[i]));

    for(int i = 0;i < n;i++)
        a.emplace(i);

    vector<bool> fuck(n);

    while(sz(a)) {
        int v = (*a.begin());
        a.erase(a.begin());



        if (deg[v] >= k) {
            a.emplace(v);
            cout << 1 << " " << sz(a) << endl;
            for(int i : a) {
                cout << i + 1 << " ";
            }
            cout << endl;
            return;
        }   

        if (!fuck[v] && deg[v] == k - 1) {
            bool bad = false;
            for(int v1 : gr[v]) {
                for(int v2 : gr[v]) {
                    if (v1 == v2) break;
                    int id = lower_bound(all(gr1[v1]), v2) - gr1[v1].begin();
                    if (id == sz(gr1[v1]) || gr1[v1][id] != v2) bad = true;
                }
                if (bad) break;
            }
            if (bad) {
                for(int i : gr[v]) {
                    if (deg[i] == k - 1) fuck[i] = true;
                }
            }else {
                cout << 2 << endl;
                for(int i : gr[v])
                    cout << i + 1 << " ";
                cout << v + 1 << endl;
                return;
            }
        }

        for(int i : gr[v]) {
            a.erase(i);
            gr[i].erase(v);
            deg[i]--;
            a.emplace(i);
        }
    }
    cout << -1 << endl;
}


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}