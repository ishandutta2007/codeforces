#include<bits/stdc++.h>

using namespace std;

#define int long long 

signed main() {
	int t;
	cin >> t;
	while(t--)
		 {
		 	string s; cin >> s;
		 	int a = 0, b= 0;
		 	for(int i = 0; i < (long long)s.size();++i) {
		 		a += (s[i] - 'a' + 1);
		 	}
		 	if (s.size() % 2) {
		 		int g = 1000;
		 		g = min(g, (int)s[0] - 'a' + 1);
		 		g = min(g, (int)s.back() - 'a' + 1);
		 		a -= g; b += g;
		 	}
		 	if (a > b) {
		 		cout << "Alice ";
		 	} else {
		 		cout << "Bob ";
		 	}
		 	cout << abs(a-b) << '\n';
		 }
}