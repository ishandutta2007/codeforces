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
		int n;
		cin >> n;
		string ans;
		for (int i=9; i; --i) {
			if (n<=i) {
				ans=(char)('0'+n)+ans;
				break;
			}
			ans=(char)('0'+i)+ans;
			n-=i;
		}
		cout << ans << "\n";
	}
	return 0;
}