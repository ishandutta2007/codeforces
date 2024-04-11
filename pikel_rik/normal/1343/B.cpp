#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define inf INFINITY
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        if ((n/2) % 2 != 0) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (int i = 1; i <= n/2; i++) {
            cout << 2*i << " ";
        }
        for (int i = 1; i < n/2; i++) {
            cout << 2*i - 1 << " ";
        }
        cout << n - 1 + n/2 << "\n";
    }

    return 0;
}