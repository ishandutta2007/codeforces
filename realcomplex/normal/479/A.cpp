#include <iostream>
using namespace std;

int main() {
	int a,b,c;
	cin >> a >> b >> c;
	int sum = 0;
	if(a * b * c > sum){
		sum = a * b * c;
	}
	if((a + b) * c > sum){
		sum = (a + b) * c;
	}
	if(a + b + c > sum){
		sum = a + b + c;
	}
	if(a * (b + c) > sum){
		sum = a * (b + c) ;
	}
	cout << sum;
	return 0;
}