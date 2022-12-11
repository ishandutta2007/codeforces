#include <bits/stdc++.h>
using namespace std;

int main() {
	char d;
	cin >> d;
	if(d > 91){
		d -= 32;
	}
	cout << d;
	while(cin >> d){
		cout << d;
	}
	return 0;
}