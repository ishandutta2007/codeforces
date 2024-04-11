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

    vi h(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];

    ll c = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (c + h[i] - h[i+1] < 0) {
            ans += h[i + 1] - h[i] - c;
            c = 0;
        }
        else c += h[i] - h[i+1];
    }

    cout << ans << "\n";
    return 0;
}