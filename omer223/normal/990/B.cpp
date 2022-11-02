#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <bitset>
#include <stack>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e6 + 5;
ll a[sz], n;


int main() {
	fast;
	ll k;
	cin >> n >> k;
	foru(i, 0, n)cin >> a[i];
	sort(a, a + n);
	vector<pii> v;
	int cnt = 1;
	foru(i, 1, n) {
		if (a[i] != a[i - 1]) {
			v.pb(mp(a[i - 1], cnt));
			cnt = 1;
		}
		else cnt++;
	}
	v.pb(mp(a[n - 1], cnt));
	sort(v.begin(), v.end());
	ll tot = v.back().second;
	foru(i, 0, v.size() - 1) { if (v[i + 1].first - v[i].first > k)tot+=v[i].second; }
	cout << tot << endl;
	return 0;
}