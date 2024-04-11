#include "bits/stdc++.h"
using namespace std;
int main(){
	int a , b , c , d;
	int x , y;
	cin >> a >> b >> c >> d;
	a = abs(a - c);
	b = abs(b - d);
	cin >> x >> y;
	if((a % x) == 0 && (b % y) == 0 && ((a / x) % 2) == ((b / y) % 2)){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
}