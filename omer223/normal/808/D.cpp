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
#include <unordered_set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e5;
int n;
ll x;
ll a[sz];


int main() {
	fast;
	cin >> n;
	ll sm = 0;
	foru(i, 0, n) {
		cin >> a[i]; sm += a[i];
	}
	if (sm & 1 || n == 1) {
		cout << "NO" << endl;
		return 0;
	}
	ll target = sm >> 1;
	for (int time = 0; time < 2; time++) {
		ll cr = 0;
		unordered_set<ll> vis;
		for (int i = 0; i < n; i++) {
			cr += a[i];
			vis.insert(a[i]);
			if (cr == target) {
				cout << "YES" << endl;
				return 0;
			}
			else if (cr > target && vis.find(cr - target) != vis.end()) {
				cout << "YES" << endl;
				return 0;
			}
		}
		reverse(a, a + n);
	}
	cout << "NO" << endl;
	return 0;
}