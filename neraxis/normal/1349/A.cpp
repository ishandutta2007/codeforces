#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 200005;

vector<int> v[N];
int n, a[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int foo = a[i];
        for (int j = 2; j * j <= foo; j++) {
            if (foo % j) continue;
            int cnt = 0;
            while (foo % j == 0) {
                cnt++;
                foo /= j;
            }
            v[j].pb(cnt);
        }
        if (foo) v[foo].pb(1);
    }
    if (n == 2) return cout << 1LL * a[1] * a[2] / __gcd(a[1], a[2]), 0;
    long long ans = 1;
    for (int i = 1; i <= 200000; i++) {
        sort(all(v[i]));
        if (v[i].size() == n) {
            for (int j = 1; j <= v[i][1]; j++) {
                ans *= i;
            }
        } else if (v[i].size() == n - 1) {
            for (int j = 1; j <= v[i][0]; j++) {
                ans *= i;
            }
        }
    }
    cout << ans;
    return 0;
}