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


int main() {
	fast;
	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		if (s.length() <= 10)cout << s << endl;
		else cout << s[0] << s.length() - 2 << s.back() << endl;
	}
	return 0;
}