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
		string s;
		cin >> s;
		cout << ((s[0]=='y'||s[0]=='Y')&&(s[1]=='e'||s[1]=='E')&&(s[2]=='s'||s[2]=='S')?"YES":"NO") << "\n";
	}
	return 0;
}