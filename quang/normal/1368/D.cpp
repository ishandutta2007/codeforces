#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int a[N];
int num[30];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j < 20; j++) {
            if (a[i] >> j & 1) {
                num[j]++;
            }
        }
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        int cur = 0;
        for (int j = 19; j >= 0; j--) {
            cur *= 2;
            if (num[j]) {
                num[j]--;
                cur++;
            }
        }
        res += 1ll * cur * cur;
    }
    cout << res << endl;
    return 0;
}