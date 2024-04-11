#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int a[N];
int tot[N];
map<pair<int, int>, int> m;
long long sum = 0;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        tot[i] = 0;
    }
    int q;
    cin >> q;
    while (q--) {
        int s, t, u;
        cin >> s >> t >> u;
        if (m.count({s, t})) {
            int id = m[{s, t}];
            m.erase({s, t});
            sum -= max(0, a[id] - tot[id]);
            tot[id]--;
            sum += max(0, a[id] - tot[id]);
        }
        if (u > 0) {
            m[{s, t}] = u;
            sum -= max(0, a[u] - tot[u]);
            tot[u]++;
            sum += max(0, a[u] - tot[u]);
        }
        cout << sum << '\n';
    }       
    return 0;
}