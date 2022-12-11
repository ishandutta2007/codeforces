#include <iostream>
using namespace std;

int main() {
	
	char n;
	string vards = "hello";
	while(cin >> n){
		if(n == vards[0]){
			vards.erase(0,1);
		}
	}
	if(vards.empty()){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}