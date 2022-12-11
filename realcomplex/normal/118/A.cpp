#include <iostream>
using namespace std;

int main() {
	char burt;
	string veidot;
	while(cin >> burt){
		if(burt < 91 ){
			burt += 32;
		}
		
		if(burt != 'a'&& burt != 'e'&& burt != 'y'&& burt != 'i'&& burt != 'o' && burt != 'u'){
			veidot+='.';
			veidot += burt;
		}
	}
	cout << veidot;
	return 0;
}