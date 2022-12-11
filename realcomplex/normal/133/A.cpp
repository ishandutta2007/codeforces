#include <iostream>
using namespace std;
 
int main() {
	bool c = false;
	char d;
	while(cin >> d){
		if(d == 'H'  || d == 'Q' || d == '9'){
			c = true;
		}
	}
	if(c == true){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}