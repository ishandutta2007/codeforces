#include <iostream>

using namespace std;

string str;
bool found = false;

int main() {
	cin >> str;
	for(int i = 0;str[i];i++) {
		if(str[i] == '0') {
			found = true;
			str[i] = 'x';
			break;
		}
	}
	if(!found) {
		str[0] = 'x';
	}
	for(int i = 0;str[i];i++) {
		if(str[i] != 'x') {
			cout << str[i];
		}
	}
	cout << endl;
	return 0;
}