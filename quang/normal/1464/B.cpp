#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
char s[N];
int x, y;
int pre[2][N], suf[2][N];
long long preTot[2][N], sufTot[2][N];
int sum[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> (s + 1);
    n = strlen(s + 1);
    cin >> x >> y;
    long long base = 0;
    int num[2] = {0, 0};

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + (s[i] == '?');
        if (s[i] == '?') continue;
        if (s[i] == '1') {
            base += 1ll * x * num[0];
            num[1]++;
        } else {
            base += 1ll * y * num[1];
            num[0]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        pre[0][i] = pre[0][i - 1];
        pre[1][i] = pre[1][i - 1];
        preTot[0][i] = preTot[0][i - 1];
        preTot[1][i] = preTot[1][i - 1];
        if (s[i] == '1') pre[1][i]++;
        else if (s[i] == '0') pre[0][i]++;
        else {
            preTot[0][i] += pre[0][i];
            preTot[1][i] += pre[1][i];
        }
    }
    for (int i = n; i ; i--) {
        suf[0][i] = suf[0][i + 1];
        suf[1][i] = suf[1][i + 1];
        sufTot[0][i] = sufTot[0][i + 1];
        sufTot[1][i] = sufTot[1][i + 1];
        if (s[i] == '1') suf[1][i]++;
        else if (s[i] == '0') suf[0][i]++;
        else {
            sufTot[0][i] += suf[0][i];
            sufTot[1][i] += suf[1][i];
        }
    }
    long long res = 1e18;
    for (int i = 1; i <= n; i++) {
        // 0 1
        long long foo = 0;
        foo += 1ll * x * sum[i] * (sum[n] - sum[i]);
        foo += 1ll * y * preTot[1][i] + 1ll * x * (sufTot[1][1] - sufTot[1][i + 1]);
        foo += 1ll * x * (preTot[0][n] - preTot[0][i]) + 1ll * y * sufTot[0][i + 1];
        res = min(res, foo);

        foo = 0;
        foo += 1ll * y * sum[i] * (sum[n] - sum[i]);
        foo += 1ll * x * preTot[0][i] + 1ll * y * (sufTot[0][1] - sufTot[0][i + 1]);
        foo += 1ll * y * (preTot[1][n] - preTot[1][i]) + 1ll * x * sufTot[1][i + 1];
        res = min(res, foo);
    }
    cout << res + base << endl;
    return 0;
}