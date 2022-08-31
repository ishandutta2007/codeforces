#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e3 + 5;

int n, a[N];
vector<int> pos[8];

bool f(int l) {
    vector<int> extra(8), perm(8);
    for (int i = 8 - l % 8; i < 8; i++)
        extra[i] = 1;

    iota(all(perm), 0);

    do {
        do {
            int ok = 0;
            for (int i : perm) {
                if (l / 8 + extra[i] == 0) continue;

                int idx = lower_bound(all(pos[i]), ok) - pos[i].begin();
                idx += l / 8 + extra[i] - 1;
                if (idx >= pos[i].size()) {
                    ok = -1;
                    break;
                }
                if (idx >= 0)
                    ok = pos[i][idx];
            }

            if (ok != -1)
                return true;

        } while (next_permutation(all(extra)));
    } while (next_permutation(all(perm)));

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], pos[--a[i]].push_back(i);

    int lo = 1, hi = n;

    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (f(mid))
            lo = mid;
        else hi = mid - 1;
    }

    cout << lo << "\n";
    return 0;
}