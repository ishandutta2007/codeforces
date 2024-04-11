#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <deque>
#include <iterator>
#include <sstream>
#define endl "\n"
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const ld eps = 1e-13;
string rev(string s) {
	string t = "";
	for (auto x : s) {
		if (x == '0') t += '1';
		else t += '0';
	}
	return t;
}
signed main() {
	int tt; cin >> tt;
	while (tt --> 0) {
		int n; string a,t;
		cin >> n >> a >> t;
		vector <int> ans, b;
		for (auto x : t) b.push_back((int)(x - '0'));
		deque <int> deq;
		int flag = 1;
		for (auto x : a) deq.push_back((int)(x - '0'));
		for (int i = n - 1; i >= 0; --i) {
			int cur;
			if (flag)
				cur = deq.back();
			else
				cur = deq.front();
			if (!flag) cur = 1 - cur;
			if (cur == b[i]) {
				if (flag) deq.pop_back();
				else deq.pop_front();
			}
			else {
				int st;
				if (flag) st = deq.front();
				else st = deq.back();
				if (!flag) st = 1 - st;
				if (st != cur) ans.push_back(1);
				ans.push_back(i + 1);
				if (flag) deq.pop_front();
				else deq.pop_back();
				flag = 1 - flag;
			}
		}
		cout << ans.size() << ' ';
		for (auto x : ans) cout << x << ' ';
		cout << endl;
	}
	return 0;
}