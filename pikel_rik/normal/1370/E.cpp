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
const int N = 1e6 + 5;

int n;
string s, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> s >> t;
    int c1 = count(all(s), '1'), c2 = count(all(t), '1');

    if (c1 != c2) {
        cout << "-1\n";
        return 0;
    }

    string temp1, temp2;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i])
            temp1 += s[i], temp2 += t[i];
    }

    s = temp1;
    t = temp2;
    n = s.length();

    if (s.empty()) {
        cout << "0\n";
        return 0;
    }

    int c = 0, best1 = -inf, best2 = inf;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            c++;
        else c--;
        best1 = max(best1, c);
        best2 = min(best2, c);
    }

    cout << best1 - best2 << "\n";
    return 0;
}