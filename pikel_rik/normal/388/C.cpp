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
const int N = 100 + 5;

int n, s[N];
vector<int> a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        a[i].resize(s[i]);
        for (int j = 0; j < s[i]; j++) cin >> a[i][j];
    }

    int sum1 = 0, sum2 = 0;
    vector<int> v;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i] / 2; j++) {
            sum1 += a[i][j];
            sum2 += a[i][s[i] - j - 1];
        }
        if (s[i] & 1)
            v.push_back(a[i][s[i] / 2]);
    }

    sort(all(v), greater<>());
    for (int i = 0; i < v.size(); i++) {
        if (i % 2 == 0)
            sum1 += v[i];
        else sum2 += v[i];
    }

    cout << sum1 << " " << sum2 << "\n";
    return 0;
}