#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int ntest; cin >> ntest;
    while(ntest--) {
        long long ans = 1;
        int n, k; cin >> n >> k;

        for(int i = 0; i < k; ++i) ans = (1ll * ans * n) % mod;
        cout << ans << endl;
    }

    return 0;
}