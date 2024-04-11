#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int solve(vector<int> &v) {
	int n=v.size();
	int x=*min_element(v.begin(), v.end());
	int res=x;
	vector<int> c={};
	for (int& i: v) {
		i-=x;
		if (i==0) {
			if (c.size())
				res+=solve(c);
			c.clear();
		}
		else
			c.push_back(i);
	}
	if (c.size())
		res+=solve(c);
	res=min(res, n);
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vector<int> a(n); for (int& i: a) cin >> i;
	cout << solve(a);
	return 0;
}