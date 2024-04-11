#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, k;
char s[N];
int l[2][N], r[2][N];

int check(int ll, int rr, int need, int filled) {
    if (need == filled) {
        int x = r[need][1];
        if (x >= ll - 1) {
            x = r[need][rr + 1];
        }
        int y = l[need][n];
        if (y <= rr + 1) {
            y = l[need][ll - 1];
        }
        return y - x - 1 > k;
    } else {
        int x = min(r[need][1], ll - 1);
        int y = max(l[need][n], rr + 1);
        return y - x - 1 > k;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    cin >> (s + 1);
    l[0][0] = l[1][0] = 1;
    for (int i = 1; i <= n; i++) {
        l[0][i] = l[1][i] = i + 1;
        l[s[i] - '0'][i] = l[s[i] - '0'][i - 1];
    }
    r[0][n + 1] = r[1][n + 1] = n;
    for (int i = n; i; i--) {
        r[0][i] = r[1][i] = i - 1;
        r[s[i] - '0'][i] = r[s[i] - '0'][i + 1];
    }

    int x = r[0][1];
    int y = l[0][n];
    if (y - x - 1 <= k) {
        cout << "tokitsukaze" << endl;
        return 0;
    }
    x = r[1][1];
    y = l[1][n];
    if (y - x - 1 <= k) {
        cout << "tokitsukaze" << endl;
        return 0;
    }
    int found = 0;
    for (int i = 1; i + k - 1 <= n & !found; i++) {
        for (int kk = 0; kk < 2; kk++) {
            int foo = 1;
            for (int j = 0; j < 2; j++) {
                foo &= check(i, i + k - 1, j, kk);
            }

            found |= foo;
        }
    }
    cout << (found ? "once again" : "quailty") << endl;
    return 0;
}