#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <strstream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <cmath>

#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(__v) __v.size()
#define FI(_a, _b) for (int i = _a; i < _b; i++)
#define RI(_a, _b) for (int i = _a; i >= _b; i--)

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, a, b, k, f;
	cin >> n >> a >> b >> k >> f;
	set<pair<string, string> > se;
	map<set<string>, int> m;
	int sums = 0;
	string prev1, prev2;
	cin >> prev1 >> prev2;
	set<string> asd;
	asd.insert(prev1);
	asd.insert(prev2);
	m.insert(mp(asd, a));
	asd.clear();
	for (int i = 1; i < n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		set<string> asdf;
		asdf.insert(s1);
		asdf.insert(s2);
		if (s1 == prev2) {
			if (m.find(asdf) != m.end()) {
				m[asdf] += b;
			}
			else {
				m.insert(mp(asdf, b));
			}
		}
		else {
			if (m.find(asdf) != m.end()) {
				m[asdf] += a;
			}
			else {
				m.insert(mp(asdf, a));
			}
		}
		prev1 = s1; prev2 = s2;
	}
	vector <int> v;
	for (auto i = m.begin(); i != m.end(); i++) {
		v.pb(i->y);
	}
	
	sort(v.begin(), v.end());
	int num = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (k == 0) break;
		if (v[i] > f) {
			v[i] = f;
			num++;
		}
		if (num == k) break;
	}
	long long sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}
	cout << sum;
	cin >> n;
	return 0xffffffff + 0x1;
}