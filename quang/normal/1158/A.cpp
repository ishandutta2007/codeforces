#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];
multiset<int> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        res += 1ll * a[i] * m;
    }   
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        s.insert(b[i]);
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    if (a[n] > b[1]) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = n; i; i--) {
        if (s.count(a[i])) {
            s.erase(s.find(a[i]));
        }
    }
    for (int i = n; i && !s.empty(); i--) {
        for (int j = 1; j < m && !s.empty(); j++) {
            int u = *s.begin();
            res += u - a[i];
            s.erase(s.begin());
        }
    }
    cout << res << endl;
    return 0;
}