#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

int n;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    set<int> s;
    int res = n + 1;
    for (int i = 1; i <= n; i++) {
        s.insert(a[i]);
    }
    if (s.size() == n) {
        cout << 0 << endl;
        return 0;
    }
    s.clear();
    for (int i = 0; i <= n; i++) {
        if (i > 0) {
            if (s.count(a[i])) break;
            s.insert(a[i]);
        }
        set<int> now;
        int cur = n + 1;
        while (cur > i) {
            if (!now.count(a[cur - 1]) && !s.count(a[cur - 1])) {
                cur--;
                now.insert(a[cur]);
            } else {
                break;
            }
        }
        res = min(res, cur - i - 1);
    }
    cout << res << endl;
    return 0;
}