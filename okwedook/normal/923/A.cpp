#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
int main() {
	int n;
	cin >> n;
	vector<int> euclid(n + 1, -1);
	for (int i = 2; i <= n; ++i) 
		if (euclid[i] == -1) {
			euclid[i] = 1;
			for (int j = i * 2; j <= n; j += i)
				euclid[j] = i;
		}
	int ans = 1000000000;
	for (int x1 = n - euclid[n] + 1; x1 <= n; ++x1)
		ans = min(ans, x1 - euclid[x1] + 1);
	cout << ans;
    return 0;
}