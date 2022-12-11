#include <iostream>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	int sk;
	for(int i = 0;i<n;i++){
		cin >> sk;
		if(360 % (180 - sk) == 0){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}