#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ordered_set = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int maxN = 4e5 + 5;

int n, k, a[maxN];
map<int, int> cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    cnt[a[0]] = 1;

    int ptr1 = 0, ptr2 = 1;
    ll ans = 0;

    set<int> full;
    if (k == 1) full.insert(a[0]);

    while (ptr1 < n and ptr2 <= n) {
        if (!full.empty())
            ans += n - ptr2 + 1;
        else {
            while (ptr2 < n) {
                cnt[a[ptr2]] += 1;

                if (cnt[a[ptr2]] == k) {
                    full.insert(a[ptr2]);
                    ptr2 += 1;
                    break;
                }
                ptr2 += 1;
            }
            if (!full.empty())
                ans += n - ptr2 + 1;
        }
        cnt[a[ptr1]] -= 1;
        if (cnt[a[ptr1]] == k - 1)
            full.erase(a[ptr1]);

        ptr1 += 1;
    }

    cout << ans << "\n";
    return 0;
}