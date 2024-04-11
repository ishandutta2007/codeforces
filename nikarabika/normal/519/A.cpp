#include <bits/stdc++.h>

using namespace std;

int p(char c){
	if(c == 'q')
		return 9;
	if(c == 'r')
		return 5;
	if(c == 'b')
		return 3;
	if(c == 'n')
		return 3;
	if(c == 'p')
		return 1;
	return 0;
}

int main(){
	int a = 0, b = 0;
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++){
			char c;
			cin >> c;
			if(c <='z' and c >= 'a')
				a += p(c);
			else
				b += p(c - 'A' + 'a');
		}
	if(a > b)
		cout << "Black" << endl;
	else if(a < b)
		cout << "White" << endl;
	else
		cout << "Draw" << endl;
	return 0;
}