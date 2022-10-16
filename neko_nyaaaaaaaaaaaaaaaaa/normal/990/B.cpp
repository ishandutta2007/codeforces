#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<int> a(1000001);
	while (n--) {
		int x;
		cin >> x;
		a[x]++;
	}
	
	int cr = 0;
	int ans = 0;
	
	for (int i = 1000000; i; i--) {
		if (a[i]) {
			if (cr == 0) {ans += a[i];}
			cr = k;
		} else {
			if (cr) {cr--;}
		}
	}
	
	cout << ans;
	
	return 0;
}