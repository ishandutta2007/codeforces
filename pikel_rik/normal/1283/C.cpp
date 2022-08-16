#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, f[N];
bool mark[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> f[i];

    set<int> s;
    for (int i = 1; i <= n; i++) s.insert(i);

    for (int i = 1; i <= n; i++) {
        s.erase(f[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (!f[i]) {
            f[i] = *s.rbegin();
            s.erase(*s.rbegin());
            mark[i] = true;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (f[i] == i) {
            for (int j = 1; j <= n; j++) {
                if (i != j and mark[j]) {
                    swap(f[i], f[j]);
                    break;
                }
            }
            break;
        }
    }

    for (int i = 1; i <= n; i++) cout << f[i] << ' '; cout << '\n';
    return 0;
}