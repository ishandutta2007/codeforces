#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n;
vector<int> a;

int solve(vector<int> &c, int bits) {
	if (c.empty() || bits < 0)
		return 0;
	vector<int> l, r;
	for (int i : c) {
		if ((i&(1<<bits))==0)
			l.push_back(i);
		else
			r.push_back(i);
	}
	if (l.empty())
		return solve(r, bits-1);
	if (r.empty())
		return solve(l, bits-1);
	return min(solve(l,bits-1),solve(r,bits-1))+(1<<bits);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	a.resize(n);
	for (int i=0; i<n; ++i)
		cin >> a[i];
		
	cout << solve(a, 30) << '\n';
	return 0;
}