#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	string s;
	cin >> s;
	if(s[0] >= 'a'){
		s[0] ^= 32;
	}
	cout << s;
	return 0;
}