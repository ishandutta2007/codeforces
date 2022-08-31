#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    const double pi = acos(-1.0);
    cout << fixed << setprecision(10);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        n *= 2;

        double A = (double)360 / n;
        double B = (180 - A) / 2;

        double r = 1 / cos(B * pi / 180);
        cout << sqrt(r * r - 1) << "\n";
    }
    return 0;
}