#include<bits/stdc++.h>

using namespace std;

#define int long long 

signed main() {
	int que;
	cin >> que;
	while(que--) {
		int a,b; cin >> a >> b;
		if (a== 0) cout << "1";
		else {
			cout << a + 2*b + 1;
		}
		cout << "\n";
	}
}