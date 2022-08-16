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
        int n;
        cin >> n;

        int a1 = n % 10, a2 = (n/10) % 10, a3 = (n/100) % 10, a4 = (n/1000) % 10, a5 = (n/10000) % 10;

        int c = 0;
        if (a1) c += 1;
        if (a2) c += 1;
        if (a3) c += 1;
        if (a4) c += 1;
        if (a5) c += 1;

        cout << c << "\n";
        if (a1) cout << a1 << " ";
        if (a2) cout << a2 * 10 << " ";
        if (a3) cout << a3 * 100 << " ";
        if (a4) cout << a4 * 1000 << " ";
        if (a5) cout << a5 * 10000 << " ";
        cout << "\n";
    }
    return 0;
}