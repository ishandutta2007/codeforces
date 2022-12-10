#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, ans = 0;
	string s, t;
	cin >> n;
	cin >> s >> t;
	for(int i = 0; i < n; i++){
		int x = s[i] - '0', y = t[i] - '0';
		if(x < y)
			ans += min(y - x, 10 - y + x);
		else
			ans += min(x - y, 10 - x + y);
	}
	cout << ans << endl;
	return 0;
}