/*
_NUUUUUUU_
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>

using namespace std;
typedef long long ll;

int main() {
	ll k, n;
	cin >> n >> k;
	vector<int> v(n);
	multiset<int> s;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	string s1;
	cin >> s1;
	int last = (ll) s1[0];
	ll nu = 0, cnt=0;
	for (int i = 0; i < n; i++) {
		int m = v[i];
		if (last != s1[i]) {
			nu += cnt;
			cnt = m;
			s.clear();
			last = s1[i];
			s.insert(m);
		}
		else {
			s.insert(m);
			cnt += m;
			if (s.size() == k + 1) {
				cnt -= *s.begin();
				s.erase(s.find(*s.begin()));
			}
		}
	}
	nu += cnt;
	cout << nu;
}