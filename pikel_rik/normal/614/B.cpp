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
const int N = 1e5 + 5;

int n;
string a[N];

bool good(const string &s) {
    int c = 0;
    for (char i : s) {
        if (i == '1')
            c++;
        if (i != '1' and i != '0')
            return false;
    }
    return c <= 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int power = 0;
    string s;

    for (int i = 0; i < n; i++) {
        if (a[i] == "0") {
            cout << "0\n";
            return 0;
        }

        if (good(a[i]))
            power += a[i].length() - 1;
        else s = a[i];
    }

    if (s.empty()) cout << "1";
    else cout << s;
    for (int i = 0; i < power; i++)
        cout << "0"; cout << "\n";
    return 0;
}