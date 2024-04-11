#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	string str;
	while(cin >> str){
		for(int i = 0; i < str.length(); i++){
			if(str[i] == '.')
				cout << 0;
			else cout << (str[i++ + 1] == '.' ? 1 : 2);
		}
		cout << endl;
	}
	return 0;
}