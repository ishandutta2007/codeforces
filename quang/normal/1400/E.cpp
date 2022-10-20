#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int n;
int a[N];
int minId[N][N];

long long solve(int l, int r, int delta) {
    if (l > r) return 0;
    int minVal = a[minId[l][r]];
    long long res = minVal - delta;
    int cur = l;
    while (cur <= r) {
        int val = a[minId[cur][r]];
        if (val == minVal) {
            res += solve(cur, minId[cur][r] - 1, minVal);
            cur = minId[cur][r] + 1;
        } else {
            res += solve(cur, r, minVal);
            break;
        }
    }
    res = min(res, 1ll * r - l + 1);

    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        minId[i][i] = i;
        for (int j = i + 1; j <= n; j++) {
            if (a[minId[i][j - 1]] > a[j]) minId[i][j] = j;
            else minId[i][j] = minId[i][j - 1];
        }
    }
    cout << solve(1, n, 0) << endl;
    return 0;
}