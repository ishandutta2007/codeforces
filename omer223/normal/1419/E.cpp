#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

vector<int> getDivisors(ll n) {
	vector<int> ans;
	for (ll i = 1; i * i <= n; i++) {
		if (n%i == 0) {
			if (i != 1)ans.pb(i);
			if (i*i != n)ans.pb(n / i);
		}
	}
	return ans;
}

vector<int> getPrimes(ll n) {
	vector<int> ans;
	for (int i = 2; i * i <= n; i++) {
		if (n%i == 0) {
			int cnt = 0;
			while (n%i == 0) {
				cnt++;
				n /= i;
			}
			ans.pb(i);
		}
	}
	if (n != 1)ans.pb(n);
	return ans;
}

void solve() {
	ll n;
	cin >> n;
	vector<int> p = getPrimes(n);
	vector<int> d = getDivisors(n);
	if (d.size() == 3 && p.size() == 2) {
		for (int k : d)cout << k << " ";
		cout << endl << 1 << endl;
	}
	else if (p.size() == 1) {
		for (int k : d)cout << k << " ";
		cout << endl << 0 << endl;
	}
	else {
		vector<int> ans, smalldiv, restdiv;
		for (int k : d) {
			if (k%p[0] == 0)smalldiv.pb(k);
			else restdiv.pb(k);
		}
		int myp = p.size();
		for (int i = 1; i < myp; i++) {
			if (i != myp - 1) {
				for (int k : restdiv) {
					if (k % p[i] == 0 && k != p[i] * p[i + 1])ans.pb(k);
				}
				ans.pb(p[i] * p[i + 1]);
				vector<int> tmp;
				for (int k : restdiv) {
					if (k % p[i] != 0)tmp.pb(k);
				}
				restdiv = tmp;
			}
			else {
				for (int k : restdiv)ans.pb(k);
			}
		}
		int l = -1, r = -1;
		for (int k : smalldiv) {
			if (l == -1 && k%p[0] == 0 && k%p[1] == 0) {
				l = k;
			}
			else if (r == -1 && k % p[0] == 0 && k % p[myp - 1] == 0) {
				r = k;
			}
		}
		ans.pb(r);
		for (int k : smalldiv) {
			if (k != l && k != r)ans.pb(k);
		}
		ans.pb(l);
		for (int k : ans)cout << k << " ";
		cout << endl<<0<<endl;
	}
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}