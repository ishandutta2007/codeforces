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

int x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> x;

    if (x == 1)
        cout << "1\n";
    else if (x == 2 or x == 4 or x == 5)
        cout << "3\n";
    else if (x == 3)
        cout << "5\n";
    else if (x <= 13)
        cout << "5\n";
    else if (x <= 25)
        cout << "7\n";
    else if (x <= 41)
        cout << "9\n";
    else if (x <= 61)
        cout << "11\n";
    else if (x <= 85)
        cout << "13\n";
    else cout << "15\n";
    return 0;
}