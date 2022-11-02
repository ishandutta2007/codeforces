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

const int sz = 2e3;
int n;
int arr[sz];
ll ask(int l, int r) {
	cout << "? " << l << " " << r << endl;
	fflush(stdout);
	ll ans;
	cin >> ans;
	return ans;
}

int main() {
	fast;
	cin >> n;
	ll prv = ask(1, 2), bef = prv;
	for (int i = 3; i <= n; i++) {
		ll tmp = ask(1, i);
		arr[i] = tmp - prv;
		prv = tmp;
	}
	arr[2] = ask(2, 3) - arr[3];
	arr[1] = bef - arr[2];
	cout << "! ";
	for (int i = 1; i <= n; i++)cout << arr[i] << " ";
	return 0;
}