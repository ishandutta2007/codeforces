#define _CRT_SECURE_NO_WARNINGS
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
#include <list>
#include <set>
#include <stack>
#include <tuple>
#include <map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tri;


const int absz = 26;
int n;
ll t;
string s;
ll cnt[absz];


int main() {
	fast;
	ll cur = 0;
	cin >> n >> t >> s;
	foru(i, 0, n - 2)cnt[s[i] - 'a']++;
	t -= ((1 << (s[n - 1] - 'a')) - (1 << (s[n - 2] - 'a')));
	foru(i, 0, absz)cur -= (cnt[i] * (1 << i));
	ll need = t - cur;
	if (need & 1 || need < 0) {
		cout << "NO\n";
	}
	else {
		ford(i, absz - 1, 0) {
			ll needbig = need / (1 << (i + 1));
			need -= min(needbig, cnt[i])*(1 << (i + 1));
		}
		if (need == 0)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}