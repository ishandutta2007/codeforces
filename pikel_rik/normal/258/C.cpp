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

ll modexp(ll x, ll n) {
    if (x == 0)
        return 0;
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return ans;
}

const int N = 1e5 + 5;
int n, a[N], cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++)
        cnt[a[i]]++;

    for (int i = 1; i < N; i++)
        cnt[i] += cnt[i - 1];

    ll end = 0;
    for (int i = 1; i <= (int)1e5; i++) {
        vector<int> div;
        for (int j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                div.push_back(j);
                if (i / j != j)
                    div.push_back(i / j);
            }
        }

        ll ans = 0;
        sort(all(div), greater<>());
        int num = cnt[N - 1] - cnt[i - 1];
        ans = modexp(div.size(), num) - modexp(div.size() - 1, num);
        ans = (ans + mod) % mod;

        for (int j = 1; j < div.size(); j++) {
            int temp = cnt[div[j - 1] - 1] - cnt[div[j] - 1];
            ans = ans * modexp(div.size() - j, temp) % mod;
        }
        end = (end + ans) % mod;
    }

    cout << end << "\n";
    return 0;
}