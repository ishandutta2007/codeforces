#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool test(string a, string b){
	return (a[1] == b[1] && abs(a[0] - b[0]) == 1) || (a[1] == b[1] && abs(a[0] - b[0]) == 2);
}

int main(){
	string a, b, c;
	cin >> a >> b >> c;
	int ans = 2; 
	// Case 1
	if(a == b || a == c || b == c){
		ans = 1;
	}
	if(a == b && b == c){
		ans = 0;
	}
	// Case 2
	if(test(a, b) || test(a, c) || test(b, c)){
		ans = 1;
	}
	if(a[1] == b[1] && b[1] == c[1]){
		char num[3];
		num[0] = a[0];
		num[1] = b[0];
		num[2] = c[0];
		sort(num, num+3);
		if(num[0] + 1 == num[1] && num[1] + 1 == num[2]){
			ans = 0;
		}
	}
	cout << ans;
}