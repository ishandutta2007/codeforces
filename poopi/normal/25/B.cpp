						/* in the name of Allah */
#include <iostream>
#include <string>
using namespace std;

int n;
string str;

int main(){
	cin >> n >> str;
	if(n % 2)
		cout << str[0];
	for(int i = n % 2; i < n; i += 2){
		cout << str[i] << str[i+1];
		if(i + 2 < n)
			cout << '-';
	}
	cout << endl;
	return 0;
}