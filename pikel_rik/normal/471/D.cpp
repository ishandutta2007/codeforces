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

int n, w, a[N], b[N];

void constructLps(const int diff_b[], vi &lps) {
    int len = 0, i = 1;
    lps[0] = 0;

    while (i < w - 1) {
        if (diff_b[i] == diff_b[len]) {
            len += 1;
            lps[i] = len;
            i += 1;
        }
        else if (len != 0) {
            len = lps[len - 1];
        }
        else {
            lps[i] = 0;
            i += 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> w;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < w; i++) cin >> b[i];

    if (w == 1) {
        cout << n << "\n";
        return 0;
    }

    int diff_a[n-1], diff_b[w-1];

    for (int i = 1; i < n; i++) diff_a[i-1] = a[i] - a[i-1];
    for (int i = 1; i < w; i++) diff_b[i-1] = b[i] - b[i-1];

    vi lps(w-1);
    constructLps(diff_b, lps);

    int i = 0, j = 0, c = 0;

    while (i < n) {
        if (diff_a[i] == diff_b[j]) {
            i += 1;
            j += 1;
        }

        if (j == w - 1) {
            c += 1;
            j = lps[j - 1];
        }
        else if (i < n and diff_a[i] != diff_b[j]) {
            if (j != 0)
                j = lps[j-1];
            else i += 1;
        }
    }

    cout << c << "\n";
    return 0;
}