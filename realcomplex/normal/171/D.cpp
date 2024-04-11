#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if(n < 5){
		cout << (n % 3) + 1;
	}
	else{
		cout << 1;
	}
	return 0;
}