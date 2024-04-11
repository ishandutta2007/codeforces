#include <bits/stdc++.h>

using namespace std;

bool can(int a,int b,int c){
	int x = 0;
	while(x * a <= c){
		if((c - (x * a)) % b == 0){
			return true;
		}
		x++;
	}
	return false;
}

int main() {
	
	int a,b,c;
	cin >> a >> b >> c;
	
	if(can(a,b,c) == false){
		cout << "No";
	}
	else{
		cout << "Yes";
	}
	return 0;
}