#include <bits/stdc++.h>

using namespace std;

int lcm(int a, int b){
	return (a * b) / __gcd(a, b);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	int n, m, z;
	cin >> n >> m >> z;

	cout << z / lcm(n, m);

	return 0;
}