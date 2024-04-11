#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int qry(int i) {
	cout << "? " << i << endl;
	int x; cin >> x;
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	int l = 1, r = n;
	while(l < r) {
		int mid = (l + r) / 2;
		if (qry(mid) < qry(mid + 1)) r = mid;
		else l = mid + 1;
	}
	cout << "! " << l << endl;
	return 0;
}