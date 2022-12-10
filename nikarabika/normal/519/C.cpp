#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int a, b, ans = 0;
	cin >> a >> b;
	for(int t = 0; t <= min(a, b/2); t++){
		int x = a - t;
		int y = b - 2 * t;
		int w = min(y, x / 2);
		if(t + w > ans)
			ans = t + w;
	}
	cout << ans << endl;
	return 0;
}