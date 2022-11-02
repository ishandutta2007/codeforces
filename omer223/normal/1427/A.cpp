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

const int sz = 50;
int a[sz], b[sz];
int n;

void solve() {
	cin >> n;
	vector<int> a;
	int sum = 0, zeros = 0, tmp;
	foru(i, 0, n) {
		cin >> tmp;
		if (tmp == 0)zeros++;
		else a.pb(tmp);
		sum += tmp;
	}
	if (sum == 0 || zeros == n) {
		cout << "NO\n";
		return;
	}
	else {
		cout << "YES\n";
		sort(a.rbegin(), a.rend());
		if (sum > 0) {
			for (int x : a)cout << x << ' ';
		}
		else {
			for (int j = a.size() - 1; j >= 0; j--)cout << a[j] << ' ';
		}
		while (zeros--)cout << 0 << ' ';
		cout << '\n';
	}

}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}