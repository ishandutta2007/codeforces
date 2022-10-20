#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n, m;
char s[N], t[N];
int cntS[2][N], cntT[2][N];
int pref[N];
char res[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> (s + 1);
    cin >> (t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);
    for (int i = 1; i <= n; i++) {
        cntS[0][i] = cntS[0][i - 1];
        cntS[1][i] = cntS[1][i - 1];
        cntS[s[i] - '0'][i]++;
    }
    for (int i = 1; i <= m; i++) {
        cntT[0][i] = cntT[0][i - 1];
        cntT[1][i] = cntT[1][i - 1];
        cntT[t[i] - '0'][i]++;
    }
    if (cntT[0][m] > cntS[0][n] || cntT[1][m] > cntS[1][n]) {
        cout << (s + 1) << endl;
        return 0;
    }
    int cur = 0;
    for (int i = 2; i <= m; i++) {
        while (cur > 0 && t[i] != t[cur + 1]) cur = pref[cur];
        cur += (t[i] == t[cur + 1]);
        pref[i] = cur;
    }

    int zero, one;
    zero = cntT[0][m] - cntT[0][pref[m]];
    one = cntT[1][m] - cntT[1][pref[m]];
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        res[i] = t[i];
    }

    cnt = m;
    cntS[0][n] -= cntT[0][m];
    cntS[1][n] -= cntT[1][m];
    // cout << cntS[0][n] << ' ' << cntS[1][n] << endl;
    while (zero <= cntS[0][n] && one <= cntS[1][n]) {
        cntS[0][n] -= zero;
        cntS[1][n] -= one;
        for (int i = pref[m] + 1; i <= m; i++) {
            res[++cnt] = t[i];
        }
    }
    for (int i = 1; i <= cntS[0][n]; i++) res[++cnt] = '0';
    for (int i = 1; i <= cntS[1][n]; i++) res[++cnt] = '1';

    cout << (res + 1) << endl;
    return 0;   
}