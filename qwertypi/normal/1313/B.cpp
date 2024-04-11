#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, x, y;
		cin >> n >> x >> y;
		int ans1 = max(1, min(n, x + y - 1));
		x = n + 1 - x; y = n + 1 - y;
		int ans2 = max(1, min(n, x + y - 2));
		cout << n + 1 - ans2 << ' ' << ans1 << endl;
	}
}