#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	int base = 240;

	int n, k; cin >> n >> k;

	int ans = 0, cur = 0;
	base -= k;

	while(ans < n && base >= cur + 5){
		++ans;
		cur += 5;
		base -= cur;
	}

	cout << ans;

}