#include <bits/stdc++.h>

using namespace std;

#define BP __builtin_popcount

int main(){
	int n, l, r, x;
	cin >> n >> l >> r >> x;
	int c[n], ans = 0;
	for(int i = 0; i < n; i++)
		cin >> c[i];
	for(int mask = 0; mask < (1 << n); mask++){
		if(BP(mask) <= 1)
			continue;
		int Min = 1e9, Max = 0, sum = 0;
		for(int j = 0; j < n; j++) if(mask & (1 << j)){
			sum += c[j];
			Min = min(Min, c[j]);
			Max = max(Max, c[j]);
		}
		if(Max - Min >= x and sum >= l and sum <= r)
			ans++;
	}
	cout << ans << endl;
	return 0;
}