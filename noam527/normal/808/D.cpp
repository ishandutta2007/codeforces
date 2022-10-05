#include <iostream>
#include <set>
typedef long long ll;
using namespace std;
#define done cout << "YES"; return 0

int main() {
	ios::sync_with_stdio(false);
	set<ll> s1, s2;
	int n, a[100000];
	ll t = 0, ps = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], t += a[i];
	if (t % 2) {
		cout << "NO";
		return 0;
	}
	t /= 2;
	s1.insert(t), ps = 0;
	for (int i = 0; i < n; i++) {
		ps += a[i];
		if (s1.find(a[i]) != s1.end()) { done; }
		if (t - ps >= 0)
			s1.insert(s1.begin(), t - ps);
	}
	if (s1.find(0) != s1.end()) { done; }
	s2.insert(t), ps = 0;
	for (int i = n - 1; i >= 0; i--) {
		ps += a[i];
		if (s2.find(a[i]) != s2.end()) { done; }
		if (t - ps >= 0)
			s2.insert(s2.begin(), t - ps);
	}
	if (s2.find(0) != s2.end()) { done; }
	cout << "NO";
}