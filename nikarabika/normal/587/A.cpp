//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Iz wayTn' 230u

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int cnt[2000 * 1000 + 85 - 69];
	memset(cnt, 0, sizeof cnt);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		cnt[x]++;
	}
	int ans = 0;
	for(int i = 0; i < 2000 * 1000; i++){
		cnt[i + 1] += cnt[i] / 2;
		ans += cnt[i] & 1;
	}
	cout << ans << endl;
	return 0;
}