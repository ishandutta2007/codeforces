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
const int N = 1e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    cout << min(n + 1, m + 1) << "\n";
    int x = 0, y = m;

    while (y >= 0 and x <= n) {
        cout << x << " " << y << "\n";
        x += 1;
        y -= 1;
    }
    return 0;
}