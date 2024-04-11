#include <bits/stdc++.h>
using namespace std;
int main () {
	int n; cin >> n;
	string s; cin >> s;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') cnt1++;
		else cnt2++;
	}
	printf("%d\n", cnt1 + cnt2 + 1);
	return 0;
}