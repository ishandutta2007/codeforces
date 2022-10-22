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
		string ans;
		for (int i=0; i<min(a, b); ++i)
			ans+="01";
		if (a>=b)
			ans+=string(a-b, '0');
		else
			ans+=string(b-a, '1');
		cout << ans << "\n";
	}
	return 0;
}