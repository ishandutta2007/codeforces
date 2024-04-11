#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int cur = 0;
	int n, d; 
	cin >> n >> d;
	string s;
	cin >> s;
	int ans = 1;
	while (cur + d < n-1) {
		ans++;
		int tmp = cur+d;
		while (s[tmp] != '1') {
			tmp--;
		}
		if (tmp == cur) {cout << -1; return 0;}
		cur = tmp;
	}
	cout << ans;
	
	return 0;
}