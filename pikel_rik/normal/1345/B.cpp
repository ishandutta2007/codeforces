#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int c = 0;
        while (n >= 2) {
            ll lo = 0, hi = n, mid;

            while (lo < hi) {
                mid = lo + (hi - lo + 1) / 2;
                if (3 * (mid * (mid + 1)) / 2 - mid > n) hi = mid - 1;
                else lo = mid;
            }

            n -= 3 * (lo * (lo + 1)) / 2 - lo;
            c += 1;
        }

        cout << c << "\n";
    }
    return 0;
}