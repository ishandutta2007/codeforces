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

#define MAXN 10000

int n;
bool is_nprime[MAXN + 1];

int main() {
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;

    for (int i = 2; i <= MAXN; i++) {
        if (!is_nprime[i]) {
            for (int j = i + i; j <= MAXN; j += i) {
                is_nprime[j] = true;
            }
        }
    }

    vector<int> ans;

    for (int i = 2; i <= MAXN; i++) {
        if (is_nprime[i]) {
            continue;
        }

        int j = i;
        while (j <= n) {
            ans.pb(j);
            j *= i;
        }
    }

    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}