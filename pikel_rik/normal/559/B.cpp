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

string smallest(string s) {
    if (s.length() % 2 != 0) return s;
    string s1 = smallest(s.substr(0, s.length() / 2));
    string s2 = smallest(s.substr(s.length() / 2, s.length() / 2));
    if (s1 < s2)
        return s1 + s2;
    return s2 + s1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    string temp1 = smallest(s1), temp2 = smallest(s2);
    if (temp1 == temp2) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}