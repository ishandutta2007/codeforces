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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 5e5;
ll a[sz];
ll n;

int main() {
	fast;
	cin >> n;
	foru(i, 0, n - 1)cin >> a[i + 2];
	int x = n;
	vector<int> ans;
	while (x != 1) {
		ans.pb(x);
		x = a[x];
	}
	ans.pb(1);
	for (auto x = ans.rbegin(); x != ans.rend(); x++)cout << *x << " ";
	cout << endl;
	return 0;
}