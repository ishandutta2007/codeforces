#include <bits/stdc++.h>
using namespace std;

bool ir(int lol){
	while(lol > 0){
		if(lol % 10 != 4 && lol % 10 != 7){
			return false;
		}
		lol /= 10;
	}
	return true;
}
bool num(int sk){
	for(int i = 1;i<=sk;i++){
		if(sk % i == 0 && ir(i) == true){
			return true;	
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	if(num(n) == true){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}