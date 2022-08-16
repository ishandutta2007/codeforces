#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 5;

int n, fr[N], bk[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> fr[i] >> bk[i];

    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[fr[i]]++;
        if (fr[i] != bk[i])
            cnt[bk[i]]++;
    }

    vector<int> cand;
    for (auto &p : cnt) {
        if (p.second >= (n + 1) / 2)
            cand.push_back(p.first);
    }

    int best = inf;
    for (int x : cand) {
        int c = 0;
        for (int i = 0; i < n; i++)
            c += (fr[i] == x);

        best = min(best, max(0, (n + 1) / 2 - c));
    }

    if (best == inf) best = -1;
    cout << best << "\n";

    return 0;
}