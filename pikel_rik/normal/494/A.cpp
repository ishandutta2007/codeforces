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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;

    int n = s.length();
    vector<int> ans;

    int c1 = 0, c2 = 0;
    for (int i = 0; i < n && c1 >= c2; i++) {
        if (s[i] == '(')
            c1 += 1;
        else if (s[i] == ')')
            c2 += 1;
        else {
            ans.push_back(1);
            c2 += 1;
        }
    }

    if (c1 < c2) {
        cout << "-1\n";
        return 0;
    }

    ans.back() += c1 - c2;
    c1 = 0, c2 = 0;
    int ptr = 0;

    for (int i = 0; i < n && c1 >= c2; i++) {
        if (s[i] == '(')
            c1 += 1;
        else if (s[i] == ')')
            c2 += 1;
        else c2 += ans[ptr++];
    }

    if (c1 < c2) {
        cout << "-1\n";
        return 0;
    }

    for (int i : ans) cout << i << "\n";
    return 0;
}