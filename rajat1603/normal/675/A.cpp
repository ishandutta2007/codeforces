#include "bits/stdc++.h"
using namespace std;
int a , b , c;
int main(){
	cin >> a >> b >> c;
	b -= a;
	if(c == 0){
		if(b == 0){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	else if((b % c) == 0 && ((b / c) >= 0)){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
}