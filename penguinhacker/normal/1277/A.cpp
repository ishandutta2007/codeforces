#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n;

void solve() {
	cin >> n;
	int length=0;
	int m=n;
	int firstDig;
	while (m) {
		length++;
		if (m<10)
			firstDig=m;
		m/=10;
	}
	int ans = 9*(length-1)+firstDig;
	int compareNum = 0;
	int mult = 1;
	while (length--) {
		compareNum += firstDig*mult;
		mult*=10;
	}
	if (n<compareNum)
		ans--;
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();

	return 0;
}