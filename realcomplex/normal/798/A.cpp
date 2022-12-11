#include <iostream>
using namespace std;

int main() {
	string test;
	char rezerve;
	cin >> test;
	string check;
	bool can = false;
	for(int i = 0;i<test.size();i++){
		check = test;
		for(int x = 97;x<123;x++){
			check[i] = x;
			if(check == string(check.rbegin(),check.rend()) && test != check){
				can = true;
			}
		}
	}
	if(can == true){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}