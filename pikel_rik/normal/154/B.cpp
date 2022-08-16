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

int n, m, state[N];
set<int> cnt[N];

int check(int x) {
    if (!cnt[x].empty())
        return *cnt[x].begin();

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            if (!cnt[i].empty())
                return *cnt[i].begin();
            if (x / i != i and !cnt[x / i].empty())
                return *cnt[x / i].begin();
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    while (m--) {
        char c; int i;
        cin >> c >> i;

        if (c == '+') {
            if (state[i]) {
                cout << "Already on\n";
                continue;
            }

            int temp = check(i);

            if (temp == 0) {
                state[i] = 1;
                for (int j = 2; j * j <= i; j++) {
                    if (i % j == 0) {
                        cnt[j].insert(i);
                        if (i / j != j)
                            cnt[i / j].insert(i);
                    }
                }
                cnt[i].insert(i);
                cout << "Success\n";
            }
            else {
                cout << "Conflict with " << temp << "\n";
            }
            continue;
        }

        if (state[i] == 1) {
            state[i] = 0;
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    cnt[j].erase(i);
                    if (i / j != j)
                        cnt[i / j].erase(i);
                }
            }
            cnt[i].erase(i);
            cout << "Success\n";
        }
        else {
            cout << "Already off\n";
        }
    }
    return 0;
}