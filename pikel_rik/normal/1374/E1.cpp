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
const int N = 2e5 + 5;

int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;

    vector<int> a1(1), a2(1), a3(1);
    for (int i = 0; i < n; i++) {
        int t, a, b;
        cin >> t >> a >> b;

        if (!a and !b) continue;
        if (a and b)
            a1.push_back(t);
        else if (a)
            a2.push_back(t);
        else a3.push_back(t);
    }

    if (a1.size() + a2.size() < k + 2 or a1.size() + a3.size() < k + 2) {
        cout << "-1\n";
        return 0;
    }

    sort(all(a1));
    sort(all(a2));
    sort(all(a3));

    for (int i = 1; i < a1.size(); i++)
        a1[i] += a1[i - 1];

    for (int i = 1; i < a2.size(); i++)
        a2[i] += a2[i - 1];

    for (int i = 1; i < a3.size(); i++)
        a3[i] += a3[i - 1];

    int best = inf;

    for (int i = 0; i < a1.size(); i++) {
        if (k - i >= a2.size() or k - i >= a3.size() or k < i) continue;
        best = min(best, a1[i] + a2[k - i] + a3[k - i]);
    }

    cout << best << "\n";
    return 0;
}