#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL a, b;

LL gcd_nama(LL x, LL y){
	if(y == 0)
		return 0;
	return x / y + gcd_nama(y, x % y);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b;
	cout << gcd_nama(a, b) << endl;
	return 0;
}