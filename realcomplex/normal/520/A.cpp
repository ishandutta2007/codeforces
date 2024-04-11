#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	char b;
	for(int x = 0;x<n;x++){
		cin >> b;
		if(b < 97){
			b = b + 32;
		}
		if(alpha.find(b) != -1){
			alpha.erase(alpha.find(b),1);
		}
	}
	if(alpha.empty()){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}