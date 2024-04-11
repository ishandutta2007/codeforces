#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--) {
		cin >> n;
		if (n==2) {
			cout << "1\n0\n";
			continue;
		}
		if (n==3) {
			cout << "1\n1\n";
			continue;
		}
		n--;
		int need=0;
		for (int i=1; i<=29; ++i) {
			if ((1<<(i+1))-2>=n) {
				need=i;
				break;
			}
		}
		int bac=1;
		int k=0;
		cout << need << '\n';
		for (int i=0; i<need-2; ++i) {
			cout << (1<<i) << ' ';
			bac+=(1<<i);
			k+=bac;
		}
		n-=k;
		if (n>=(1<<need)) {
			cout << (1<<(need-2)) << ' ';
			bac+=(1<<(need-2));
			n-=bac;
			cout << n-bac << '\n';
		}
		else {
			int x=n/2;
			int y=n-x;
			cout << x-(1<<(need-2)) << ' ' << y-x << '\n';
		}
	}
	return 0;
}