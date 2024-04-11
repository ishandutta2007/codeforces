#include <iostream>

#define LL long long 

using namespace std;

LL a, b;

int main() {
	cin >> a >> b;
	if(b-a+1 < 3) {
		cout << -1 << endl;
	}else if(b-a+1 == 3) {
		if(a%2 == 0) {
			cout << a << " " << a+1 << " " << a+2 << endl;
		}else {
			cout << -1 << endl;
		}
	}else {
		if(a%2 == 1) {
			a++;
		}
		cout << a << " " << a+1 << " " << a+2 << endl;
	}
	return 0;
}