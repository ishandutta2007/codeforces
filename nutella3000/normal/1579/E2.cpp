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
const int N = 2e5 + 3;


void run() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), BIT(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; b[i] = a[i];
    }
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    for (int i = 0; i < n; ++i)
        a[i] = lower_bound(all(b), a[i]) - b.begin();

    auto get_s = [&](int r) {
        int res = 0;
        for (++r; r; r -= r&-r)
            res += BIT[r];
        return res;
    };
    auto set_e = [&](int id) {
        for (++id; id <= n; id += id&-id)
            ++BIT[id];
    };
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int num = get_s(a[i] - 1);
        chkmin(num, i - get_s(a[i]));
        res += min(num, i - num);
        set_e(a[i]);
    }
    cout << res << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}