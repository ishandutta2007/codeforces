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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int y, k, n;
    cin >> y >> k >> n;

    int x;
    x = k - y % k;

    if (x + y > n) {
        cout << "-1\n";
        return 0;
    }

    while (x + y <= n) {
        cout << x << " ";
        x += k;
    }
    cout << "\n";
    return 0;
}