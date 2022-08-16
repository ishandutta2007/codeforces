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

    int n, k;
    cin >> n >> k;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    set<int> s;
    map<int, int> m;

    int l = 0, r = 0;
    s.insert(a[0]);
    m[a[0]] += 1;

    int best_l = -1, best_r = -1;

    while (l < n and r < n) {
        while (r < n - 1 and s.size() < k) {
            r += 1;
            s.insert(a[r]);
            m[a[r]] += 1;
        }
        while (s.size() == k and l < n) {
            if ((best_l == -1) or (r - l + 1 < best_r - best_l + 1)) {
                best_l = l;
                best_r = r;
            }
            m[a[l]] -= 1;
            if (m[a[l]] == 0) s.erase(a[l]);
            l += 1;
        }
        if (r == n-1) break;
    }

    cout << (best_l != -1 ? best_l + 1 : -1) << " " << (best_r != -1 ? best_r + 1 : -1) << "\n";
    return 0;
}