#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    scanf("%d", &T);
    while (T--) {
        long long N;
        cin >> N;
        long long ans = N * (N + 1) / 2;
        for (int i = 0; i < 63; i++) {
            if ((1ll << i) <= N) ans -= 2ll * (1ll << i);
        }
        cout << ans << endl;
    }
}