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

int a, b, c, d;
int c1, c2;

void calc() {
    c1 = c2 = 0;
    if (a & 1)
        c1++;
    else c2++;

    if (b & 1)
        c1++;
    else c2++;

    if (c & 1)
        c1++;
    else c2++;

    if (d & 1)
        c1++;
    else c2++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> a >> b >> c >> d;
        calc();

        if (a > 0 and b > 0 and c > 0 and c1 > 1) {
            a--;b--;c--;
            d += 3;
            calc();
        }

        if (c1 > 1)
            cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}