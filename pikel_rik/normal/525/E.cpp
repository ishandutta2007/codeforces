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
const int N = 26;

int n, k, a[N];
ll S, fact[19], ans;

map<ll, int> cnt[26];

void recurse1(int pos, int c, ll sum) {
    if (pos == -1) {
        cnt[c][sum]++;
        return;
    }

    recurse1(pos - 1, c, sum);

    if (a[pos] + sum <= S)
        recurse1(pos - 1, c, sum + a[pos]);

    if (a[pos] <= 18 and fact[a[pos]] + sum <= S and c < k)
        recurse1(pos - 1, c + 1, sum + fact[a[pos]]);
}

void recurse2(int pos, int c, ll sum) {

    if (pos == n) {
        for (int i = c; i <= k; i++) {
            if (cnt[i - c].count(S - sum))
                ans += cnt[i - c][S - sum];
        }
        return;
    }

    recurse2(pos + 1, c, sum);

    if (a[pos] + sum <= S)
        recurse2(pos + 1, c, sum + a[pos]);

    if (a[pos] <= 18 and fact[a[pos]] + sum <= S and c < k)
        recurse2(pos + 1, c + 1, sum + fact[a[pos]]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i <= 18; i++) fact[i] = fact[i-1] * i;

    cin >> n >> k >> S;
    for (int i = 0; i < n; i++) cin >> a[i];

    recurse1(n / 2 - 1, 0, 0);
    recurse2(n / 2, 0, 0);

    cout << ans << "\n";
    return 0;
}