#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin >> n;
	vector<string> inp(n);
	for(auto &i : inp) cin >> i;
	int ans = 6;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			vector<bool> used(6, 0);
			for (int k = 0; k < 6; ++k)
				if (inp[i][k] == inp[j][k])
					used[k] = true;
			int count = 0;
			for (auto k : used) count += !k;
			ans = min(ans, (count - 1) / 2);
		}
	}
	cout << ans;
	//system("pause");
    return 0;
}