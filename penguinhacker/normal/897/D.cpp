#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int ins(vector<int>& d, int x) {
	auto it=upper_bound(d.begin(), d.end(), x);
	if (it==d.end()) {
		d.push_back(x);
		return d.size();
	} else {
		*it=x;
		return it-d.begin()+1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, c;
	cin >> n >> m >> c;
	vector<int> a, b;
	while(a.size()+b.size()<n) {
		int x;
		cin >> x;
		if (x<=c/2) {
			cout << ins(a, x) << endl;
		} else {
			cout << n-ins(b, -x)+1 << endl;
		}
	}
	return 0;
}