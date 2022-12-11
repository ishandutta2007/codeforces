#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int sk = 0;
	char d;
	int total = 0;
	while(cin >> d){
		total *= 10;
		total += int(d - 48);
		sk++;
	}
	int p10 = pow(10,sk - 1);
	cout << p10 - (total % p10);
	return 0;
}