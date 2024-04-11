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

const ll md = 1e9 + 7;
const int mx = 1e5 + 5;
ll sm[mx + 5];

ll modpow(ll a, ll b) {
	if (!b)return 1;
	ll tmp = modpow(a, b >> 1);
	tmp *= tmp;
	tmp %= md;
	if (b & 1) {
		tmp *= a;
		tmp %= md;
	}
	return tmp;
}

void prec() {
	sm[0] = 1;
	for (ll i = 1; i <= mx; i++) sm[i] = (sm[i - 1] + (modpow(10, i)*(i+1))) % md;
}


int main() {
	fast;
	string s;
	cin >> s;
	prec();
	int n = s.length();
	ll ret = 0, crnum = 0;
	ford(i, n - 1, 0) {
		crnum += (modpow(10, n - i - 1)*(s[i] - '0'));
		crnum %= md;
		ret += (crnum*i);
		ret %= md;
	}
	foru(i, 0, n) {
		ll dig = s[i] - '0';
		int right = n - i - 1;
		if(right)ret += dig * (sm[right - 1]);
		ret %= md;
	}
	cout << ret << endl;
	return 0;
}