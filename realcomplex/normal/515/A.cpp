#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c;
	cin >> a >> b >> c;
	a = abs(a);
	b = abs(b);
	int len = a + b;
	if(c >= len){
		if((c - len) % 2 == 0){
			cout << "Yes";
		}
		else{
			cout << "No";
		}
	}
	else{
		cout << "No";
	}
	return 0;
}