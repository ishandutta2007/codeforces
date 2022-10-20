#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int L = 260;
const int ALPHA = 26;

int n, q;
int dp[L][L][L];
char s[N];
int nxt[ALPHA][N];
string a[4];

int getNxt(char u, int pos) {
    if (pos == n + 1) return n + 1;
    return nxt[u - 'a'][pos + 1];
}

void update(int i, int j, int k) {
    if (i == 0 && j == 0 && k == 0) {
        dp[i][j][k] = 0;
        return;
    }
    dp[i][j][k] = n + 1;
    if (i) {
        dp[i][j][k] = min(dp[i][j][k], getNxt(a[1][i - 1], dp[i - 1][j][k]));
    }
    if (j) {
        dp[i][j][k] = min(dp[i][j][k], getNxt(a[2][j - 1], dp[i][j - 1][k]));
    }
    if (k) {
        dp[i][j][k] = min(dp[i][j][k], getNxt(a[3][k - 1], dp[i][j][k - 1]));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    cin >> (s + 1);
    for (int i = 0; i < ALPHA; i++) {
        nxt[i][n + 1] = n + 1;
    }
    for (int i = n; i; i--) {
        for (int j = 0; j < ALPHA; j++) {
            nxt[j][i] = nxt[j][i + 1];
        }
        nxt[s[i] - 'a'][i] = i;
    }
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            for (int k = 0; k < L; k++) {
                dp[i][j][k] = n + 1;
            }
        }
    }
    dp[0][0][0] = 0;
    a[3] = a[1] = a[2] = "";
    while (q--) {
        char op;
        int u;
        char v;
        cin >> op >> u;
        if (op == '+') {
            cin >> v;   
            a[u] += v;
            int start[4];
            start[1] = start[2] = start[3] = 0;
            start[u] = a[u].size();
            // cout << a[1].size() << ' ' << a[2].size() << ' ' << a[3].size() << endl;
            for (int i = start[1]; i <= (int)a[1].size(); i++) {
                for (int j = start[2]; j <= (int)a[2].size(); j++) {
                    for (int k = start[3]; k <= (int)a[3].size(); k++) {
                        // cout << i << ' ' << j << ' ' << k << endl;
                        update(i, j, k);
                    }
                }
            }
        } else {
            int start[4];
            start[1] = start[2] = start[3] = 0;
            start[u] = a[u].size();
            for (int i = start[1]; i <= (int)a[1].size(); i++) {
                for (int j = start[2]; j <= (int)a[2].size(); j++) {
                    for (int k = start[3]; k <= (int)a[3].size(); k++) {
                        dp[i][j][k] = n + 1;
                    }
                }
            }
            a[u].pop_back();
        }
        cout << (dp[a[1].size()][a[2].size()][a[3].size()] <= n ? "YES" : "NO") << '\n';
    }
    return 0;
}