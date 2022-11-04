#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-8
#define mp(a, b) make_pair(a, b)
#define pb(a, b) push_back(a, b)

int n;
vector<int> a;
vector<int> ans_min;
vector<int> ans_max;

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    ans_min.resize(n, INF);
    ans_max.resize(n, 0);
    a.resize(n);

    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }

    ans_max[0] = a[n - 1] - a[0];
    ans_min[0] = a[1] - a[0];
    ans_max[n - 1] = a[n - 1] - a[0];
    ans_min[n - 1] = a[n - 1] - a[n - 2];

    for (int i = 1; i < n; i++) {
    	ans_min[i - 1] = min(ans_min[i - 1], a[i] - a[i - 1]);
    	ans_min[i] = a[i] - a[i - 1];
    	ans_max[i] = max(a[i] - a[0], a[n - 1] - a[i]);
    }

    for (int i = 0; i < n; i++) {
    	cout << ans_min[i] << " " << ans_max[i] << endl;
    }

    return 0;
}