//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL n, ans = 0;

void solve(){
	cin >> n;
	ans = n * (n + 1) / 2;
	int l = 0;
	for(int i = 0; i <= 32; i++)
		if((n >> i) & 1)
			l = i;
	cout << ans - 2 * ((1 << (l + 1)) - 1) << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}