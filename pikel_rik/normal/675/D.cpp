#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ordered_set = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 5;

int n, a[N];
map<int, int> t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        t[a[i]] = i;
    }

    ordered_set s;
    s.insert(a[0]);

    for (int i = 1; i < n; i++) {
        s.insert(a[i]);
        int ord = s.order_of_key(a[i]);

        if (ord == 0)
            cout << *s.find_by_order(1) << " ";
        else if (ord == i)
            cout << *s.find_by_order(i - 1) << " ";
        else {
            int num1 = *s.find_by_order(ord - 1), num2 = *s.find_by_order(ord + 1);
            if (t[num1] > t[num2])
                cout << num1 << " ";
            else cout << num2 << " ";
        }
    }
    return 0;
}