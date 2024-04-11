#include <bits/stdc++.h>

using namespace std;

const int N = 2e6;

int n;
int a[N];
int cnt[2][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    long long res = 0;
    int pre = 0;
    cnt[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] ^= pre;
        res += cnt[i % 2][a[i]];
        // cout << a[i] << ' ';
        cnt[i % 2][a[i]]++;
        pre = a[i];
    }
    cout << res << endl;
    return 0;
}