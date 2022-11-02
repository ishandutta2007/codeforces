#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
typedef long double ld;

const int inf = 1e15;
const int max_n = 5e3 + 4;

struct w {
    int a, b, g;

    w() {}

    w(int a, int b, int g) : a(a), b(b), g(g) {}
};

vector<pii> gr[max_n];
int f[max_n];

bool have_min = false;

bool dfs(int v, int to, int pr, int num) {
    //cout << v << endl;
    if (v == to) {
        return true;
    }

    for(auto i : gr[v]) {
        if (i.fi != pr) {
            if (dfs(i.fi, to, v, num)) {
                int e = i.se;
                //cout << e << " ";
                if (f[e] <= num) {
                    f[e] = num;
                    have_min = true;
                }
                return true;
            }
        }
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n;
    for(int i = 0;i < n - 1;i++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        gr[v1].emplace_back(v2, i);
        gr[v2].emplace_back(v1, i);
    }

    cin >> m;

    w a[m];
    for(int i = 0;i < m;i++) {
        cin >> a[i].a >> a[i].b >> a[i].g;
        a[i].a--;
        a[i].b--;
    }

    sort(a, a + m, [](w v1, w v2) {
        return v1.g > v2.g;
    });

    /*for(int i : gr[0])
        cout << i << " ";
    cout << endl;*/

    bool have_res = true;

    for(auto i : a) {
        dfs(i.a, i.b, -1, i.g);
        //cout << endl;
        //for(int j = 0;j < n - 1;j++)
        //    cout << max(1ll, f[j]) << " ";
        //cout << endl;
        if (!have_min) have_res = false;
        have_min = false;
    }

    if (!have_res) cout << -1 << endl;
    else {
        for(int i = 0;i < n - 1;i++)
            cout << max(1ll, f[i]) << " ";
    }
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();
}