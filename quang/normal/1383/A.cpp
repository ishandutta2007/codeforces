#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int CHAR = 20;

int n;
char s[N], t[N];
bool has[CHAR][CHAR];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        cin >> (s + 1);
        cin >> (t + 1);
        for (int i = 0; i < CHAR; i++) {
            for (int j = 0; j < CHAR; j++) {
                has[i][j] = 0;
            }
        }
        bool found = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == t[i]) continue;
            if (s[i] < t[i]) {
                has[s[i] - 'a'][t[i] - 'a'] = 1;
            } else {
                found = 1;
            }
        }
        if (found) {
            cout << -1 << '\n';
            continue;
        }
        int res = 0;
        for (int i = 0; i < CHAR; i++) {
            int last = -1;
            for (int j = i + 1; j < CHAR; j++) {
                if (has[i][j]) {
                    if (last == -1) res++;
                    else {
                        has[last][j] = 1;
                    }
                    last = j;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}