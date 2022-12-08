							/* in the name of Allah */
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
	int T;
	string str;
	while(cin >> str){
		int cnt = 0;
		for(int i = 0; i < str.length(); i++){
			if(str[i] >= 'A' && str[i] <= 'Z')
				cnt++;
			else cnt--;
		}
		for(int i = 0; i < str.length(); i++)
			cout << (char)(cnt > 0 ? toupper(str[i]) : tolower(str[i]));
		cout << endl;
	}
	return 0;
}