#include <bits/stdc++.h>
 
using namespace std;
 
#define aidar asadulin
 
#define int long long
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
int in[max_n], out[max_n];
int res = 0;
vector<int> gr[max_n];

void upd(int v) {
    for(int i : gr[v]) {
        gr[i].emplace_back(v);
        res -= in[i] * out[i];
        in[i]++;
        out[i]--;
        res += in[i] * out[i];
    }
    gr[v].clear();
    res -= in[v] * out[v];
    out[v] += in[v];
    in[v] = 0;
}

void solve() {
    int m;
    cin >> n >> m;

    for(int i = 0;i < m;i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        if (v1 < v2) swap(v1, v2);
        
        gr[v2].emplace_back(v1);
        in[v2]++;
        out[v1]++;
    }

    for(int i = 0;i < n;i++)
        res += in[i] * out[i];

    cout << res << endl;
    int q;
    cin >> q;
    for(int i = 0;i < q;i++) {
        int v;
        cin >> v;
        upd(v - 1);
        cout << res << endl;
    }
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}