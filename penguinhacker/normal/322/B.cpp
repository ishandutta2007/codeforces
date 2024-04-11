#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int a[3], best=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a[0] >> a[1] >> a[2];
	sort(a,a+3);
	best=a[0]/3+a[1]/3+a[2]/3;
	if (a[0]>=1) {
		a[0]--; a[1]--; a[2]--;
		best=max(best, 1+a[0]/3+a[1]/3+a[2]/3);
	}
	if (a[0]>=1) {
		a[0]--; a[1]--; a[2]--;
		best=max(best, 2+a[0]/3+a[1]/3+a[2]/3);
	}
	cout << best;
	return 0;
}