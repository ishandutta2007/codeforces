// ./a-add-and-divide.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        int a,b, inc = 0; cin >> a >> b;
        if (b == 1) {
            inc++;
            b++;
        }
        int ans = INF;
        for (int i = 0; i < 50; i++) {
            int cans = inc + i, cb = b+i, ca = a;
            while (ca > 0) {
                cans++;
                ca /= cb;
            }
            ans = min(ans, cans);
        }
        cout << ans << '\n';
    }

    return 0;
}