#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif
	
	long long n, k; cin >> n >> k;

	vector < long long > divisor;

	for(long long i = 1; i * i <= n; ++i){
		if(n % i == 0){
			divisor.push_back(i);
			if(i != n / i) divisor.push_back(n / i);
		}	
	}

	sort(divisor.begin(), divisor.end());
	if(divisor.size() >= k) cout << divisor[k - 1];
	else cout << -1;

	return 0;
}