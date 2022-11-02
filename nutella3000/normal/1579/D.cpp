#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld long double
mt19937 Rand(0);

const int inf = 1e9 + 7;
const int N = 1e5 + 3;

void run() {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int v; cin >> v;
        for (int j = 0; j < v; ++j)
            a.pb(i + 1);
    }
    vector<pii> res;
    int bl = (size(a) + 1) / 2;
    for (int i = 0; i < size(a) / 2; ++i) {
        if (a[i] != a[i + bl]) res.pb(a[i], a[i + bl]);
    }
    cout << size(res) << endl;
    for (auto i : res)
        cout << i.fi << " " << i.se << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}