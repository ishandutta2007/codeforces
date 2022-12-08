							/* in the name of Allah */
#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
	int T;
	string str;
	for(cin >> T; T--; ){
		cin >> str;
		if(str.length() <= 10)
			cout << str << endl;
		else cout << str[0] << str.length() - 2 << str[str.length() - 1] << endl;
	}
	return 0;
}