#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 1e6;
int n;
int a[sz];

int main() {
	fast;
	cin >> n;
	foru(i, 0, n)cin >> a[i];
	cout << n + 1 << '\n';
	ll tsm = 0;
	const int bnd = 1e4;
	ford(i, n - 1, 0) {
		ll tadd = (i - (a[i] + tsm) % n + n) % n;
		cout << "1 " << i + 1 << ' ' << tadd << '\n';
		tsm += tadd;
	}
	cout << "2 " << n << ' ' << n << '\n';
	return 0;
}