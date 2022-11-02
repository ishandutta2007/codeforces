#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef double ld;
 
const int inf = 1e16; 
const int max_n = 2e5 + 1;

int n;
vector<int> gr[max_n];
int used[max_n];
set<pii> res;

int cnt = 0;
void rec(int v) {
    for(int i : gr[v]) {
        if (used[i] != -1) continue;
        if (v == 0) {
            cnt++;
        }
        used[i] = v;
        res.emplace(mp(v, i));
        rec(i);
    }
}

void solve() {
    int m, D;
    cin >> n >> m >> D;

    for(int i = 0;i < m;i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        gr[v1].emplace_back(v2);
        gr[v2].emplace_back(v1);
    }
    for(int i = 0;i < n;i++)
        used[i] = -1;

    used[0] = 0;
    rec(0);
    
    if (cnt > D || gr[0].size() < D) {
        cout << "NO";
        return;
    }

    cout << "YES" << endl;

    for(int i : gr[0]) {
        if (used[i] != 0) {
            cnt++;
            res.erase(mp(used[i], i));
            res.emplace(mp(i, 0));
        }
        if (cnt == D) break;
    }

    for(auto i : res)
        cout << i.fi + 1 << " " << i.se + 1 << endl;
}
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}