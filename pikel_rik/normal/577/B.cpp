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
const int N = 1e6 + 5;

int n, m, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= m;
    }

    set<int> s;
    s.insert(a[0]);

    for (int i = 1; i < n && !s.count(0); i++) {
        vector<int> temp;
        temp.push_back(a[i]);

        for (int x : s)
            temp.push_back((x + a[i]) % m);

        for (int x : temp)
            s.insert(x);
    }

    if (s.count(0)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}