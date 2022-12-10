#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL k, a, b;

int main(){
	cin >> k >> a >> b;
	LL shif = (k - (a % k)) % k;
	a = a + shif;
	if(b < a)
		cout << 0 << endl;
	else
		cout << (b - a) / k + 1 << endl;
	return 0;
}