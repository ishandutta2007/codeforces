#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-10
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

int n;
int cnt[2000000];

int main() {
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
    	int w;
    	cin >> w;
    	cnt[w]++;
    }

    int ans = 0;
    for (int i = 0; i < 2000000 - 1; i++) {
    	cnt[i + 1] += cnt[i] / 2;
    	ans += cnt[i] % 2;
    }

    cout << ans << endl;

    return 0;
}