#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vll sums(n - k + 1);
    for (int i = 0; i < k; i++) {
        sums[0] += a[i];
    }
    for (int i = 1; i < n-k+1; i++) {
        sums[i] = sums[i - 1] + a[i + k - 1] - a[i - 1];
    }

    set<pll, greater<>> m;

    for (int i = k; i <= n - k; i++) {
        m.insert({sums[i], i});
    }

    pll temp = *(m.begin());
    ll best = sums[0] + temp.first;
    pll best_pair = {0, temp.second};

    for (int i = 1; i <= n-k; i++) {
        m.erase({sums[i-1], i-1});
        if (i + k - 1 <= n - k)
            m.erase({sums[i + k - 1], i + k - 1});
        if (i - k >= 0)
            m.insert({sums[i - k], i - k});

        if (!m.empty()) {
            temp = *(m.begin());
            if (sums[i] + temp.first > best) {
                best = sums[i] + temp.first;
                best_pair = {i, temp.second};
            }
        }
    }

    int min_b = best_pair.second;
    while (min_b) {
        min_b -= 1;
        if (sums[min_b] == sums[best_pair.second] and min_b >= best_pair.first + k)
            best_pair.second = min_b;
    }

    cout << best_pair.first + 1 << " " << best_pair.second + 1;
    return 0;
}