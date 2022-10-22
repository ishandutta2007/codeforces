#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector <int> a(n), b(n);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;
		vector <int> able, hah;
		for (int i = 0; i < n; ++i)
			if (!b[i]) 
				able.push_back(a[i]), hah.push_back(a[i]);
		sort(able.begin(), able.end());
		sort(hah.rbegin(), hah.rend());
		int last = 0;
		vector <int> a1, a2;
		for (int i = 0; i < n; ++i) {
			if (b[i]) 
				a1.push_back(a[i]), a2.push_back(a[i]);
			else
				a1.push_back(able[last]), a2.push_back(hah[last++]);
		}
		vector <int> pref1 = { 0 }, pref2 = { 0 };
		for (int i = 0; i < n && pref1.back() >= 0; ++i) 
			pref1.push_back(pref1.back() + a1[i]);
		
		for (int i = 0; i < n && pref2.back() >= 0; ++i)
			pref2.push_back(pref2.back() + a2[i]);
		if (pref1.size() > pref2.size()) 
			for (auto x : a1) cout << x << ' ';
		else
			for (auto x : a2) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}