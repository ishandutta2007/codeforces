#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, m;
vector<int> a, b;

bool sq(int x) {
	int y=sqrt(x);
	for (int i=y-1; i<=y+1; ++i)
		if (i*i==x)
			return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		int x;
		cin >> x;
		if (sq(x)) {
			a.push_back(x?1:2);
		} else {
			int y=sqrt(x);
			b.push_back(min(abs(y*y-x), abs((y+1)*(y+1)-x)));
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (a.size()>=b.size()) {
		cout << accumulate(a.begin(), a.begin()+a.size()-n/2, 0ll);
	} else {
		cout << accumulate(b.begin(), b.begin()+b.size()-n/2, 0ll);
	}
	return 0;
}