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
const int N = 5e3;

int n, a[N];

int recurse(int l = 0, int r = n - 1, int h = 0) {
    if (l == r) {
        if (a[l] > h)
            return 1;
        return 0;
    }

    int m = *min_element(a + l, a + r + 1);

    int ans = m - h;
    int cur_l = -1, cur_r = -1;

    for (int i = l; i <= r; i++) {
        if (a[i] > m and cur_l == -1)
            cur_l = cur_r = i;
        else if (a[i] > m)
            cur_r += 1;
        else if (cur_l != -1) {
            ans = ans + recurse(cur_l, cur_r, m);
            cur_l = cur_r = -1;
        }
    }

    if (cur_l != -1)
        ans += recurse(cur_l, cur_r, m);

    return min(ans, r - l + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << recurse();
    return 0;
}