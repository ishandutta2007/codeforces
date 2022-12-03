#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using old = long double;

const int N = 100100;

vector<int> g[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cout << setprecision(20) << fixed;
    int n;
    old s;
    cin >> n >> s;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 1) {
            ++cnt;
        }
    }
    cout << min(s / cnt * 2, s);
}