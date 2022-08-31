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

    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int max = *max_element(all(a)), min = *min_element(all(a));

    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == max) c1 += 1;
        else if (a[i] == min) c2 += 1;
    }

    if (max == min) cout << "0 " << (c1 * (ll)(c1 - 1)) / 2;
    else cout << max - min << " " << c1 * (ll)c2 << "\n";
    return 0;
}