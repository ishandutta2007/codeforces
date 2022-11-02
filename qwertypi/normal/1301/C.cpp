#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define int long long 
int f(int x){
	return x * (x + 1) / 2;
}

void sub(){
	int n, m;
	cin >> n >> m;
	int d = n - m;
	int p = m + 1;
	int ans = f(n) - (d % p) * f(d / p + 1) - (p - d % p) * f(d / p);
	cout << ans << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}