
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <unordered_map>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> p;
bitset<100000> sieve;

void prec() {
	for (int i = 2; i <= 30000; i++) {
		if (!sieve[i]) {
			p.pb(i);
			for (int j = i + i; j <= 30000; j += i)sieve[j] = 1;
		}
	}
}


void solve() {
	ll d;
	cin >> d;
	ll ret = 1;
	for (int i = 0; i < p.size();i ++) {
		if (p[i] > d) {
			ret = p[i];
			for (int j = i + 1; j < p.size(); j++) {
				if (p[j] - p[i] >= d) {
					ret *= p[j];
					break;
				}
			}
			break;
		}
	}
	cout << ret << '\n';
}

int main() {
	fast;
	prec();
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}