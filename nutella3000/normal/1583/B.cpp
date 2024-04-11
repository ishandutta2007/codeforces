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


const int inf = 1e9 + 7;




void run() {
    int n, m;
    cin >> n >> m;
    vector<bool> used(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c; --a, --c; --b;
        used[b] = true;
    }
    int id = 0;
    for (int i = 0; i < n; ++i)
        if (!used[i]) id = i;

    for (int i = 0; i < n; ++i) {
        if (i == id) continue;
        cout << i + 1 << " " << id + 1 << endl;
    }
}


signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}