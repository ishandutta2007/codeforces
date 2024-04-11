#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<tuple>
#include<string>
using namespace std;
int a[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		long long s,s1;
		cin >> n>>s;
		s1 = s;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			s -= a[i];
		}
		if (s >= 0) {
			cout << 0 << "\n";
			continue;
		}
		if (a[1] > s1) {
			cout << 1 << "\n";
			continue;
		}
		long long MX=a[1];
		int ind=1;
		ind = 1;
		s = 0;
		for (int i = 2; i <= n; ++i) {
			if (a[i] > MX) {
				s += a[ind];
				MX = a[i];
				ind = i;
			}
			else s += a[i];
			if (s + MX > s1) {
				cout << ind << "\n";
				break;
			}
		}
	}
	return 0;
}