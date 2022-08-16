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
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;

        if ((ll)n * (a - b) <= c + d and (ll)n * (a + b) >= c - d)
            cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}