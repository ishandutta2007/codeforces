#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	long long ans = 0;
	cin >> n >> k;
	for(int i = 0; i < k && i < n / 2; i++) 
		ans += 2 * (n - i - i) - 3;
	cout << ans << endl;
	return 0;
}