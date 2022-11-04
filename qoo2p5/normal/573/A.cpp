#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-8
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)

int n;

int main() {
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    int prev = -1;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        while (x % 2 == 0) {
            x /= 2;
        }

        while (x % 3 == 0) {
            x /= 3;
        }

        if (prev != -1 && x != prev) {
            cout << "NO\n";
            return 0;
        }

        prev = x;
    }

    cout << "YES\n";

    return 0;
}