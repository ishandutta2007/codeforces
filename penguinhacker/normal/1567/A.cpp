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
		string s;
		cin >> n >> s;
		bool t=0;
		for (int i=0; i<n; ++i) {
			if (s[i]=='U'||s[i]=='D')
				cout << (s[i]=='U'?'D':'U');
			else {
				cout << (t==0?'L':'R');
				t^=1;
			}
		}
		cout << "\n";
	}
	return 0;
}