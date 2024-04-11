#include <bits/stdc++.h>
using namespace std;
#define int long long
void sub(){
	int n, g, b;
	cin >> n >> g >> b;
	int k = (n + 1) / 2;
	cout << max(n, ((k - 1) / g) * (g + b) + (k - 1 + g) % g + 1) << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}