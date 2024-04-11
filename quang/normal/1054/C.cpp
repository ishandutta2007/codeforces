#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
int l[N], r[N];
bool used[N];
int res[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    int cur = n;
    while (1) {
        vector<int> id;
        for (int i = 1; i <= n; i++) {
            if (l[i] == 0 && r[i] == 0 && !used[i]) {
                id.push_back(i);
            }
        }
        if (id.size() == 0) {
            break;
        }
        for (int u : id) {
            res[u] = cur;
            used[u] = 1;
        }
        cur--;
        int now = 0;
        for (int i = 1; i <= n; i++) {
            if (used[i] == 1) {
                continue;
            }
            while (now < id.size() && id[now] <= i) now++;
            l[i] -= now;
            if (l[i] < 0) {
                cout << "NO\n";
                return 0;
            }
        }
        now = 0;
        reverse(id.begin(), id.end());
        for (int i = n; i; i--) {
            if (used[i] == 1) continue;
            while (now < id.size() && id[now] >= i) now++;
            r[i] -= now;
            if (r[i] < 0) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    int f = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            f = 1;
            break;
        }
    }
    if (f) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
        cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}