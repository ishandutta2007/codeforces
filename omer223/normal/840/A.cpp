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
#include <queue>
#include <set>
#include <bitset>
#include <cmath>
#include <unordered_map>
#include <map>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 3e5;
int n;
pll a[sz], b[sz];
ll res[sz];

int main() {
	fast;
	cin >> n;
	foru(i, 0, n) {
		cin >> a[i].first; a[i].second = i;
	}
	foru(i, 0, n) {
		cin >> b[i].first; b[i].second = i;
	}
	sort(a, a + n, greater<pll>());
	sort(b, b + n);
	foru(i, 0, n)res[b[i].second] = a[i].first;
	foru(i, 0, n)cout << res[i] << " ";
	cout << endl;
	return 0;
}