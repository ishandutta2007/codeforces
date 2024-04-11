#include <bits/stdc++.h>
using namespace std;

int main() {
	char a;
	int luck = 0;
	while(cin >> a){
		if(a == '4' || a == '7'){
			luck++;
		}
	}
	if(luck == 4 || luck == 7){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}