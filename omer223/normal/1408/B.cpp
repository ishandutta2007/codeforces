#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <numeric>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

const int sz = 1e2 + 5;
int a[sz], n, k;

void solve() {
	cin >> n >> k;
	set<int> s;
	int x;
	foru(i, 0, n) {
		cin >> x; s.insert(x);
	}
	if (k == 1) cout << (s.size() == 1 ? 1 : -1) << endl;
	else if (s.size() == 1)cout << 1 << endl;
	else cout << (s.size() - 1) / (k - 1) + ((s.size()-1)%(k - 1) != 0) << endl;
}


int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}