#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    long long r; cin >> r; r--;
    long long x = -1, y;
    for (long long i = 1; i * i <= r; i++) if (r % i == 0) {
        long long j = r / i - 1 - i;
        if (j > 0 && j % 2 == 0) {
            x = i, y = j / 2;
            break;
        }
    }
    if (x == -1) cout << "NO\n";
    else cout << x << " " << y << "\n";

    return 0;
}