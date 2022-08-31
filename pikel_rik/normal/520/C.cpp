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

int n;
string s;

ll modexp(ll x, ll n) {
    if (n == 0)
        return 1;
    ll ans = modexp((x * x) % mod, n / 2);
    if (n % 2)
        return (x * ans) % mod;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> s;
    vector<int> cnt(4);

    for (char c : s) {
        if (c == 'A')
            cnt[0] += 1;
        else if (c == 'C')
            cnt[1] += 1;
        else if (c == 'G')
            cnt[2] += 1;
        else cnt[3] += 1;
    }

    int best = *max_element(all(cnt)), c = 0;
    for (int i = 0; i < 4; i++) if (cnt[i] == best) c += 1;

    cout << modexp(c, n) << "\n";
    return 0;
}