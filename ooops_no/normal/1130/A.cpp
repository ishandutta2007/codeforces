/*
_NUUUUUUU_
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
typedef long long ll;
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int l = 0, r = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a < 0) {
			l++;
		}
		if (a > 0) {
			r++;
		}
	}
	if (l >= (n + 1) / 2) {
		cout << -1;
		return 0;
	}
	if (r >= (n + 1) / 2) {
		cout << 1;
		return 0;
	}
	cout << 0;
}