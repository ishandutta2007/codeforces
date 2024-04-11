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

int x;

int solve(int a) {
	if (a == 1) {
		return 1;
	}

	if (a % 2 == 0) {
		return solve(a / 2);
	} else {
		return solve(a / 2) + 1;
	}
}

int main() {
    ios::sync_with_stdio(false);
    //freopen("restore.in", "r", stdin);
    //freopen("restore.out", "w", stdout);

    cin >> x;
    cout << solve(x) << endl;

    return 0;
}