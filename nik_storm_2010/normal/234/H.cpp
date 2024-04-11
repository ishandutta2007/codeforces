#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
const int N = 3e5;

int a[N], n, m;
int num[2][N];

int solve(int state, bool print) {
    int res = 0;
    int i = 0;
    while (i < n + m) {
        int j = i + 1;
        while (j < n + m && a[num[state][j]] == a[num[state][j + 1]]) {
            j++;
        }
        if (a[num[state][j]] == 0 && j == n + m) {
              return res;
        }
        res++;
        if (print) {
            cout << j << " ";
        }
        i = j;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i + n];
    }
    int cnt = 0;
    num[0][++cnt] = 1;
    int i = 2, j = n + 1;
    while (i <= n || j <= n + m) {
        if (i > n) {
            num[0][++cnt] = j;
            j++;
            continue;
        }
        if (j > n + m) {
            num[0][++cnt] = i;
            i++;
            continue;
        }
        if (a[i] == a[num[0][cnt]]) {
            num[0][++cnt] = i;
            i++;
            continue;
        }
        if (a[j] == a[num[0][cnt]]) {
            num[0][++cnt] = j;
            j++;
            continue;
        }
        num[0][++cnt] = i++;
    }
    int ans1 = solve(0, false);
    cnt = 0;
    num[1][++cnt] = n + 1;
    i = 1, j = n + 2;
    while (i <= n || j <= n + m) {
        if (i > n) {
            num[1][++cnt] = j;
            j++;
            continue;
        }
        if (j > n + m) {
            num[1][++cnt] = i;
            i++;
            continue;
        }
        if (a[i] == a[num[1][cnt]]) {
            num[1][++cnt] = i;
            i++;
            continue;
        }
        if (a[j] == a[num[1][cnt]]) {
            num[1][++cnt] = j;
            j++;
            continue;
        }
        num[1][++cnt] = i++;
    }
    int ans2 = solve(1, false);
    int res = (ans1 < ans2 ? 0 : 1);
    for (int i = 1; i <= n + m; i++) {
        cout << num[res][i] << " ";
    }
    cout << "\n";
    cout << min(ans1, ans2) << "\n";
    solve(res, true);
    return 0;
}