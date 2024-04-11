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

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 4e5;
int n;
int a[sz], f[sz], l[sz];

void solve() {
	cin >> n;
	foru(i, 0, n) {
		f[i + 1] = 0;
		l[i + 1] = 0;
	}
	foru(i, 0, n) {
		cin >> a[i];
		l[a[i]] = i + 1;
		f[a[i]] = (f[a[i]] ? f[a[i]] : (i + 1));
	}
	vector<int> vec;
	foru(i, 0, n) {
		if (f[i + 1])vec.pb(i + 1);
	}
	sort(vec.begin(), vec.end());
	int nums = vec.size(), lb = 0, rb = 1, bst = nums - 1;
	while (rb < nums) {
		if (f[vec[rb]] <= l[vec[rb - 1]]) lb = rb;
		rb++;
		bst = min(bst, nums - (rb - lb));
	}
	cout << bst << endl;
}


int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}