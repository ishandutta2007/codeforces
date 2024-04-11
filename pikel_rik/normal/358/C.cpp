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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v;
    while (n--) {
        int x;
        cin >> x;

        if (x)
            v.push_back(x);
        else {
            if (v.size() == 1) {
                cout << "pushStack\n";
                cout << "1 popStack\n";
                v.clear();
            }
            else if (v.size() == 2) {
                cout << "pushStack\npushQueue\n";
                cout << "2 popStack popQueue\n";
                v.clear();
            }
            else if (v.size() >= 3) {
                vector<int> temp = v;
                sort(all(temp), greater<>());

                int mx1 = -1, mx2 = -1, mx3 = -1;
                for (int i = 0; i < v.size(); i++) {
                    if (mx1 == -1 and v[i] == temp[0])
                        mx1 = i;
                    else if (mx2 == -1 and v[i] == temp[1])
                        mx2 = i;
                    else if (mx3 == -1 and v[i] == temp[2])
                        mx3 = i;
                }

                for (int i = 0; i < v.size(); i++) {
                    if (i == mx1)
                        cout << "pushStack\n";
                    else if (i == mx2)
                        cout << "pushQueue\n";
                    else if (i == mx3)
                        cout << "pushFront\n";
                    else cout << "pushBack\n";
                }

                cout << "3 popStack popQueue popFront\n";
                v.clear();
            }
            else cout << "0\n";
        }
    }

    while (!v.empty())
        cout << "pushBack\n", v.pop_back();
    return 0;
}