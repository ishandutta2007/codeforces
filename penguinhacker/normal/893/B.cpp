#include <bits/stdc++.h>
using namespace std;

int n;

bool check(int x) {
	for (int k=1; k<20; ++k) {
		int b = ((1<<k)-1)*(1<<(k-1));
		if (b>x)
			break;
		if (b==x)
			return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int best = 1;
	for (int i=1; i*i<=n; ++i) {
		if (n%i==0) {
			if (check(i))
				best = i;
			if (check(n/i)) {
				best = n/i;
				break;
			}
		}
	}
	cout << best;
	return 0;
}