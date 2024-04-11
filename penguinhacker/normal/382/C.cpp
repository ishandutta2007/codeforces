#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int n, a[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	if (n==1)
		cout << -1;
	else if (n==2&&a[0]!=a[1]&&((a[0]+a[1])&1)==0) {
		int d=a[1]-a[0];
		cout << "3\n" << a[0]-d << ' ' << (a[0]+a[1])/2 << ' ' << a[1]+d;
	}
	else {
		map<int, int> mp;
		for (int i=0; i<n-1; ++i) {
			mp[a[i+1]-a[i]]++;
			if (mp.size()>2) {
				cout << 0;
				return 0;
			}
		}
		if (mp.size()==1) {
			int d=mp.begin()->first;
			if (d==0)
				cout << 1 << '\n' << a[0];
			else
				cout << "2\n" << a[0]-d << ' ' << a[n-1]+d;
		}
		else {
			int d=mp.begin()->first;
			if (mp.rbegin()->first!=2*d||mp.rbegin()->second>1)
				cout << 0;
			else {
				cout << "1\n";
				for (int i=0; i<n-1; ++i) {
					if (a[i+1]-a[i]==2*d) {
						cout << (a[i+1]+a[i])/2;
						break;
					}
				}
			}
		}
	}
	return 0;
}