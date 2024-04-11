#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];
int pos[N];
int used[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pos[a[i]] = i;
            used[i] = 0;
        }
        int f = 0;
        for (int i = 1; i <= n && !f; i++) {
            if (!used[i]) {
                int cur = i;
                for (int j = pos[i]; j <= n && !f; j++) {
                    if (used[a[j]]) break;
                    used[a[j]] = 1;
                    if (a[j] != cur) {
                        f = 1;
                        break;
                    }
                    cur++;
                }
            }
        }
        cout << (f ? "No" : "Yes") << '\n';
    }
    return 0;
}