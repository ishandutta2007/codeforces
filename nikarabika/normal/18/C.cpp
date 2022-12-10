#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n + 1];
	int s[n + 1];
	s[0] = 0;
	for(int i = 1; i <= n; i++)
		cin >> a[i], s[i] = s[i - 1] + a[i];
	if(s[n] & 1){
		cout << 0 << endl;
		return 0;
	}
	int ans = 0;
	for(int i = 1; i < n; i++)
		if(s[i] == s[n] / 2)
			ans++;
	cout << ans << endl;
	return 0;
}