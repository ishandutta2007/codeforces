#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vi a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        set<ll> s;

        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (s.find(((i + a[i]) % n + n) % n) != s.end()) {
                flag = true;
                break;
            }
            s.insert(((i + a[i]) % n + n) % n);
        }

        if (flag) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}