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
ll k;
int a[200000];
unordered_map<ll, ll> leftc;
unordered_map<ll, ll> rightc;

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }

    leftc[a[0]] = 1;

    for (int i = 2; i < n; i++) {
    	rightc[a[i]]++;
    }

    ll ans = 0;

    for (int i = 1; i < n - 1; i++) {
    	if (a[i] % k == 0) {
    		int b = a[i] / k;

    		ans += leftc[b] * rightc[b * k * k];
    	}

    	leftc[a[i]]++;
    	rightc[a[i+1]]--;
    }

    cout << ans << endl;

    return 0;
}