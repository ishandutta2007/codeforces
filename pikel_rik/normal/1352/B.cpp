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
        int n, k;
        cin >> n >> k;

        if (n == k) {
            cout << "YES\n";
            for (int i = 0; i < k; i++) cout << "1 ";
            cout << "\n";
            continue;
        }

        if (n < k) {
            cout << "NO\n";
            continue;
        }

        if (n % 2 == 0) {
            if (k > n / 2 and k % 2 != 0) {
                cout << "NO\n";
                continue;
            }
            else if (k > n / 2) {
                cout << "YES\n";
                for (int i = 1; i < k; i++) cout << "1 ";
                cout << n - (k - 1) << "\n";
                continue;
            }
            cout << "YES\n";
            for (int i = 0; i < k - 1; i++) cout << 2 << " ";
            cout << n - 2 * (k - 1) << " ";
            cout << "\n";
            continue;
        }

        if (n % 2 != k % 2) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 1; i < k; i++) cout << "1 ";
        cout << n - (k - 1) << "\n";
    }
    return 0;
}