#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int a[N];
int used[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            used[i] = 0;
        }
        int found = 0;
        for (int i = 0; i < n; i++) {
            int nxt = (i + (a[i] % n) + n) % n;
            if (used[nxt]) {
                found = 1;
                break;
            }
            used[nxt] = 1;
        }
        cout << (found ? "NO" : "YES") << '\n';
    }
    return 0;
}