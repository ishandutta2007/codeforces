#include <iostream>
#include <string>
using namespace std;

int main(){
	char ch, last;
	char vo[12] = {'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u', 'y'};
	while(cin >> ch){
		if(isalpha(ch))
			last = ch;
	}
	string res = "NO";
	for(int i = 0; i < 12; i++)
		if(vo[i] == last)
			res = "YES";
	cout << res << endl;
	return 0;
}