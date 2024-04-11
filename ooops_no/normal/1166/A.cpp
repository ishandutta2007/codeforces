#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
#include<map>
#include<deque>
#include<math.h>
#include <numeric> 
using namespace std;

#define int long long
#define pb push_back

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<int> v(150);
	int n, s = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v[(int)s[0]]++;
	}
	for (auto to : v) {
		if (to % 2 == 0) {
			s += ((to / 2) * (to / 2 - 1) / 2) * 2;
		}
		else {
			s += (to / 2) * (to / 2 - 1) / 2;
			s += (to / 2) * (to / 2 + 1) / 2;
		}
	}
	cout << s;
}