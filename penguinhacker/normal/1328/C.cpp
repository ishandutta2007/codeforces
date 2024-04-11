#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n;
string x, a, b;

void solve() {
	cin >> n >> x;
	bool comeUp=0; //check if first '0' has come up
	a="";
	b="";
	for (int i=0; i<n; ++i) {
		if (x[i]=='2') {
			if (!comeUp) {
				a+='1';
				b+='1';
			}
			else {
				a+='0';
				b+='2';
			}
		}
		else if (x[i]=='1') {
			if (!comeUp) {
				a+='1';
				b+='0';
			}
			else {
				a+='0';
				b+='1';
			}
			comeUp=1;
		}
		else {
			a+='0';
			b+='0';
		}
	}
	cout << a << '\n' << b << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();

	return 0;
}