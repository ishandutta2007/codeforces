#include <iostream>
using namespace std;

int letters[7];
//Bulbasr
//1211211
int main() {
	char letter;
	int sk = 1000000;
	while(cin >> letter){
		if(letter == 'B'){
			letters[0]++;
		}
		else if(letter == 'u'){
			letters[1]++;
		}
		else if(letter == 'l'){
			letters[2]++;
		}
		else if(letter == 'b'){
			letters[3]++;
		}
		else if(letter == 'a'){
			letters[4]++;
		}
		else if(letter == 's'){
			letters[5]++;
		}
		else if(letter == 'r'){
			letters[6]++;
		}
	}
	letters[1] /= 2;
	letters[4] /= 2;
	for(int x = 0;x<7;x++){
		if(letters[x] < sk){
			sk = letters[x];
		}
	}
	cout << sk;
	return 0;
}