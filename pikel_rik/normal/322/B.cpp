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

    int r, g, b;
    cin >> r >> g >> b;

    int ans = r / 3 + g / 3 + b / 3;

    if (r > 0 and g > 0 and b > 0) {
        ans = max(ans, 1 + (r - 1) / 3 + (g - 1) / 3 + (b - 1) / 3);
        ans = max(ans, 2 + (r - 2) / 3 + (g - 2) / 3 + (b - 2) / 3);
    }
    cout << ans;
    return 0;
}