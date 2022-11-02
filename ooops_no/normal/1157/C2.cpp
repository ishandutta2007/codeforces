#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
#include<map>
#include<deque>
#include<math.h>

using namespace std;

#define int long long
#define pb push_back
#define ld long double
#define mp make_pair

signed main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int  l = 0, r = n - 1, mn = 0;
	vector<char> ans, ans1;
	bool x = 0;
	while (l <= r ) {
		if (v[l] == v[r]) {
			x = 1;
			for (auto to : ans) {
				ans1.pb(to);
			}
			break;
		}
		if ((v[l] < v[r]) && (v[l] > mn)) {
			mn = v[l];
			l++;
			ans.pb('L');
		}
		else if (v[r] > mn){
			mn = v[r];
			r--;
			ans.pb('R');
		}
		else if (v[l] > mn){
			mn = v[l];
			l++;
			ans.pb('L');
		}
		else {
			break;
		}
	}
	if (x) {
		int mn1 = mn;
		for (int j = l; j <= r; j++) {
			if (mn < v[j]) {
				ans.pb('L');
				mn = v[j];
			}
			else {
				break;
			}
		}
		mn = mn1;
		for (int j = r; j >= l; j--) {
			if (mn < v[j]) {
				ans1.pb('R');
				mn = v[j];
			}
			else {
				break;
			}
		}
		if (ans.size() > ans1.size()) {
			cout << ans.size() << endl;
			for (auto to : ans) {
				cout << to;
			}
		}
		else {
			cout << ans1.size() << endl;
			for (auto to : ans1) {
				cout << to;
			}
		}
		return 0;
	}
	cout << ans.size() << endl;
	for (auto to : ans) {
		cout << to ;
	}
}