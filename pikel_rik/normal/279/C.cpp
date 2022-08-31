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
    cin >> n >> m;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vi up(n), down(n);

    for (int i = 1; i < n; i++) {
        up[i] = up[i-1];
        down[i] = down[i-1];

        if (a[i-1] > a[i])
            down[i] += 1;
        else if (a[i-1] < a[i])
            up[i] += 1;
    }

    while (m--) {
        int l, r;
        cin >> l >> r;

        l -= 1; r -= 1;

        if (down[r] - down[l] == 0 or up[r] - up[l] == 0) {
            cout << "Yes\n";
            continue;
        }

        int idx = lower_bound(up.begin() + l, up.begin() + r + 1, up[r]) - up.begin();

        if (down[idx] - down[l] == 0)
            cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}