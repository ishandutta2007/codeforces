#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, k;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    a[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] ^= a[i - 1];
    }
    map<int, int> cnt;
    cnt[0] = 1;
    long long res = 1ll * n * (n + 1) / 2ll;
    int mask = (1 << k) - 1;
    for (int i = 1; i <= n; i++) {
        if (cnt[a[i]] < cnt[a[i] ^ mask]) {
            res -= cnt[a[i]];
            cnt[a[i]]++;
        } else {
            res -= cnt[a[i] ^ mask];
            cnt[a[i] ^ mask]++;
        }
    }
    cout << res << endl;
    return 0;
}