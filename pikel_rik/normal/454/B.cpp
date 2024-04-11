#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 998244353;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int pos = -1;
    if (a[0] > a[1])
        pos = 1;

    for (int i = max(1, pos + 1); i < n; i++) {
        if (pos == -1 and a[i] < a[i-1])
            pos = i;
        else if (pos != -1 and a[i] < a[i-1]) {
            cout << "-1\n";
            return 0;
        }
    }


    if (pos == -1) cout << "0\n";
    else if (a[pos] != *min_element(all(a)) or a[n-1] > a[0]) cout << "-1\n";
    else cout << n - pos << "\n";

    return 0;
}