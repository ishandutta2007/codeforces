#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int x, n, m;
        cin >> x >> n >> m;

        while ((x/2) + 10 <= x and n--) {
            x /= 2;
            x += 10;
//            cout << x << " ";
        }

        if (x <= 10 * m)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}