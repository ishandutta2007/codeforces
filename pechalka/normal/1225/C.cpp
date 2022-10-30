#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <set>
#include <string>

using namespace std;

int main(){
	int n, p;
	cin >> n >> p;
	int ans = 1000;
	for (int k = 0; k < 64; ++k){
		int x = n - p * k;
		if (x >= 0) {
			if (__builtin_popcount(x) <= k && x >= k)
				ans = min(ans, k);
		}
	}
	if (ans == 1000)
		cout << -1;
	else
		cout << ans;
	return 0;
}