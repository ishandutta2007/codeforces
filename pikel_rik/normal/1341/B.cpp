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
        int n, k;
        cin >> n >> k;

        vi a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int best = 0, best_val = 0;
        for (int i = 1; i < k-1 and i < n-1; i++) {
            if (a[i] > a[i-1] and a[i] > a[i+1])
                best_val += 1;
        }

        int cur = best_val;
        for (int i = 1; i + k - 1 < n; i++) {
            if (a[i] > a[i-1] and a[i] > a[i+1])
                cur -= 1;
            if (a[i + k - 2] > a[i + k - 3] and a[i + k - 2] > a[i + k - 1])
                cur += 1;
            if (cur > best_val) {
                best_val = cur;
                best = i;
            }
//            cout << cur << " ";
        }

        cout << best_val + 1 << " " << best + 1 << "\n";
    }
    return 0;
}