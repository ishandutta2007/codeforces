#include <iostream>

using namespace std;

int c1[2][1111];
int c2[2][1111];

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		s = "#"+s;
		for (int i = 0; i <= n+1; i++) c1[0][i] = c1[1][i] = 0;
		for (int i = 0; i <= n+1; i++) c2[0][i] = c2[1][i] = 0;
		for (int i = 1; i <= n; i++) {
			c1[0][i] = c1[0][i-1]+(s[i]!='0');
			c1[1][i] = c1[1][i-1]+(s[i]!='1');
		}
		for (int i = n; i >= 1; i--) {
			c2[0][i] = c2[0][i+1]+(s[i]!='0');
			c2[1][i] = c2[1][i+1]+(s[i]!='1');
		}
		int r = n;
		for (int i = 0; i <= n; i++) {
			int u1 = c1[0][i]+c2[1][i+1];
			int u2 = c1[1][i]+c2[0][i+1];
			r = min(r,min(u1,u2));
		}
		cout << r << "\n";
	}
}