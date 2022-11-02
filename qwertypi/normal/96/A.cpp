#include <iostream>

using namespace std;

int main(){
	string s;
	cin >> s;
	for(int i=0;i<(int)s.size()-6;i++){
		char c = s[i];
		bool OK = true;
		for(int j=1;j<7;j++){
			if(s[i+j] != s[i]){
				OK = false;
				break;
			}
		}
		if(OK){
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}