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

    int n, m;
    cin >> m >> n;

    double ans = 0;
    for (int k = 0; k < m; k += 1) {
        ans += (m - k) * (pow((double)1 - (double)k/m, n) - pow((double)1 - (double)(k+1)/m, n));
    }

    cout << ans;
    return 0;
}