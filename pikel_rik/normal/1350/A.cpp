#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        for (int i = 2; i <= n; i++) {
            if (n % i == 0) {
                n += i;
                break;
            }
        }

        cout << n + 2 * (k - 1) << "\n";
    }
    return 0;
}