#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int T , n;
int x[1010] , y[1010];

int main() {
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
		sort(x + 1 , x + n + 1) , sort(y + 1 , y + n + 1);
		if(n % 2 == 1) cout << 1 << endl;
		else cout << 1ll * (x[n / 2 + 1] - x[n / 2] + 1) * (y[n / 2 + 1] - y[n / 2] + 1) << endl; 
	}
	return 0;
}