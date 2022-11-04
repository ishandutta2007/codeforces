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
vector<int> h;
vector<int> ans;

int main() {
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    h.resize(n);
    ans.resize(n, INF);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int m = 0;
    for (int i = 1; i <= n; i++) {
        m = min(m + 1, min(h[i - 1], i));
        ans[i - 1] = m;
    }

    m = 0;
    for (int i = n; i >= 1; i--) {
        m = min(m + 1, min(h[i - 1], i));
        ans[i - 1] = min(ans[i - 1], m);
    }

    cout << *max_element(ans.begin(), ans.end()) << "\n";

    return 0;
}