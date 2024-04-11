#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, m, p, a[N], b[N];
map<int, int> cntb, cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    for (int i = 1; i <= m; i++)
        cntb[b[i]]++;

    vector<int> ans;
    int unq = cntb.size();

    for (int i = 0; i < p; i++) {
        if (i + 1 + (m - 1) * (ll)p > n) break;

        int c = unq;
        cnt.clear();

        for (int j = 1 + i; j <= 1 + i + (m - 1) * p; j += p) {
            if (cnt[a[j]] == cntb[a[j]])
                c++;
            cnt[a[j]]++;
            if (cnt[a[j]] == cntb[a[j]])
                c--;
        }

        if (c == 0)
            ans.push_back(1 + i);

        for (int j = 1 + i + m * p; j <= n; j += p) {
            if (cnt[a[j]] == cntb[a[j]])
                c++;
            cnt[a[j]]++;
            if (cnt[a[j]] == cntb[a[j]])
                c--;

            if (cnt[a[j - m * p]] == cntb[a[j - m * p]])
                c++;
            cnt[a[j - m * p]]--;
            if (cnt[a[j - m * p]] == cntb[a[j - m * p]])
                c--;

            if (c == 0)
                ans.push_back(j - (m - 1) * p);
        }
    }

    sort(all(ans));
    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " "; cout << "\n";

    return 0;
}