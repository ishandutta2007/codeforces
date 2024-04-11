#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

int main() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (auto &i : a) cin >> i;
	string s;
	cin >> s;
	char p = s[0];
	ll l = -1e9;
	ll r = 1e9;
	deque<ll> mydeq;
	for (int i = 0; i < n; ++i) {
		mydeq.push_back(a[i]);
		if (mydeq.size() == 6) mydeq.pop_front();
		if (p != s[i]) {
			if (s[i] == '1') {
				ll m = mydeq.front();
				for (auto i : mydeq) m = max(m, i);
				l = max(l, m + 1);
			}
			else {
				ll m = mydeq.front();
				for (auto i : mydeq) m = min(m, i);
				r = min(r, m - 1);
			};
		}
		p = s[i];
	}
	cout << l << ' ' << r;
	//system("pause");
    return 0;
}