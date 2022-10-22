#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		int bef=a;
		int x=b;
		while(bef%4)
			--bef;
		for (int i=bef; i<a; ++i)
			x^=i;
		cout << a+(x>0)+(x==a) << "\n";
	}
	return 0;
}