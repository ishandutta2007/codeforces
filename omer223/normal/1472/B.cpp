#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <queue>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



void solve() {
	int n;
	cin >> n;
	int o = 0, t = 0;
	foru(i, 0, n) {
		int x;
		cin >> x;
		if (x == 1)o++;
		else t++;
	}
	if (o & 1)cout << "NO\n";
	else {
		if (t % 2 == 0)cout << "YES\n";
		else {
			if (o != 0)cout << "YES\n";
			else cout << "NO\n";
		}
	}
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}