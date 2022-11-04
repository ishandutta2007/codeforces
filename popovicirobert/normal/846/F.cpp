#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 1e6;

vector <int> pos[MAXN + 1];

int a[MAXN + 1];

int main() {
    int i, n, j;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    long long ans = 0;
    for(i = 1; i <= MAXN; i++) {
        if(pos[i].size() >= 1) {
            ans += 1LL * 2 * pos[i][0] * (n - pos[i][0] + 1) - 1;
            for(j = 1; j < pos[i].size(); j++)
                ans += 1LL * 2 * (pos[i][j] - pos[i][j - 1]) * (n - pos[i][j] + 1) - 1;
        }
    }
    long long tot = 1LL * n * n;
    cout << (double) 1.0 * ans / tot * 1.0;
    return 0;
}