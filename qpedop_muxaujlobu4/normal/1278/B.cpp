#include <iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<string>
using namespace std;
int a[26];
int b[26];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int j = 0; j < t; ++j) {
		long long a, b;
		cin >> a >> b;
		if (a == b) {
			cout << 0 << endl;
			continue;
		}
		long long tmp = max(a, b) - min(a, b);
		//cout << tmp << endl;
		long long k = -1,e=1000000000-1;
		while (k+ 1 != e) {
			long long mid=(k + e) / 2;
			if (mid * (mid + 1)/2 >= tmp)e = mid;
			else k = mid;
		}
		//cout << e << " " << tmp << endl;|| (e * (e + 1) / 2 - tmp)==2
		while ((e * (e + 1) / 2 - tmp) % 2 != 0)++e;
		cout << e<<endl;
	}
	return 0;
}