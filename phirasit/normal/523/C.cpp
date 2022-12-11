#include <iostream>

#define N 10000010

using namespace std;

int lf[N], rg[N];
string s, t;

int main() {
	cin >> s >> t;
	for(int i = 0;t[i];i++) {
		if(i == 0) {
			lf[i] = (t[i] == s[i]);
		}else {
			lf[i] = lf[i-1] + (t[i] == s[lf[i-1]]);
		}
	}
	int l = t.length();
	int l2 = s.length();
	for(int i = l - 1;i >= 0;i--) {
		if(i == l) {
			rg[i] = (t[i] == s[l2-1]);
		}else {
			rg[i] = rg[i+1] + (t[i] == s[l2-rg[i+1]-1]);
		}
	}
	int ans = 0;
	for(int i = 0;t[i+1];i++) {
		ans += (lf[i] == l2 && rg[i+1] == l2);
	}
	cout << ans << endl;
	return 0;
}