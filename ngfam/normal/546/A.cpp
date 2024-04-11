#include <bits/stdc++.h>

using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	int k, n, w, s = 0;

	cin >> k >> n >> w;

	for(int i = 1; i <= w; ++i){
		s += i * k;
	}

	cout << max(0, s - n);
		
	return 0;
}