#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 2e5 + 5;
int n;
ll r, drinks = 0;
ll t[sz], l[sz];
vector<ll> places;

void input() {
	cin >> n >> r;
	foru(i, 0, n)cin >> l[i];
	foru(i, 0, n)cin >> t[i];
}

void sim(bool save) {
	ll currt = 0, remp = 0;
	foru(i, 0, n) {
		ll remw = l[i], remt = t[i];
		if (remp > remw) {
			currt += remw;
			remp -= remw;
		}
		else {
			remw -= remp;
			remt -= remp;
			currt += remp;
			remp = 0;
			if (remw * 2 > remt) {
				ll x = remt - remw;
				remw -= x;
				remt -= (2 * x);
				currt += (2 * x);
				if (save) {
					while (remw > 0) {
						if (remw >= r) {
							places.pb(currt);
							remw -= r;
							remt -= r;
							currt += r;
						}
						else {
							places.pb(currt);
							currt += remw;
							remp = (r - remw % r) % r;
							remw = 0;
						}
					}
				}
				else {
					drinks += (remw / r) + (remw % r != 0);
					remp = (r - remw % r) % r;
					currt += remw;
				}
			}
			else currt += (remw * 2);
		}
	}
}

int main() {
	fast;
	input();
	foru(i, 0, n) {
		if (l[i] > t[i]) {
			cout << -1 << '\n';
			return 0;
		}
	}
	sim(0);
	cout << drinks << '\n';
	if (drinks <= 1e5) {
		sim(1);
		for (ll x : places)cout << x << ' ';
		cout << '\n';
	}
	return 0;
}