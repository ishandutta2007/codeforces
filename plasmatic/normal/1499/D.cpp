// ./d-the-number-of-pairs.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 2e7+1;
int C, D, X,
    cpfnt[MN]; // number of factor pairs that are coprime to e/o
void solve() {
    cin >> C >> D >> X;

    ll ans = 0;
    auto check = [&] (int g) { // g -> gcd
        if ((X / g + D) % C == 0) {
            int target = (X / g + D) / C;
            ans += cpfnt[target];
        }
    };
    for (auto i = 1; i * i <= X; i++) {
        if (X % i == 0) {
            check(i);
            if (i != X/i) check(X/i);
        }
    }
    cout << ans << '\n';
}

int jmp[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    iota(jmp, jmp+MN, 0);
    cpfnt[1] = 1;
    for (auto i = 2; i < MN; i++) {
        if (jmp[i] == i) {
            for (auto j = i*2; j < MN; j += i)
                jmp[j] = i;

        }

        // we can guarantee that we go from highest -> lowest pfactor
        cpfnt[i] = 1;
        int pre = INF;
        for (auto j = i; j > 1; j /= jmp[j]) {
            if (jmp[j] != pre) {
                cpfnt[i] *= 2;
                pre = jmp[j];
            }
        }
    }

    int T;
    cin >> T;
    while (T--) {
        // Input
        
        solve();

        // Reset
    }
}