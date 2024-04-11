#include <bits/stdc++.h>

using namespace std;

int sub(){
	int a, b;
	cin >> a >> b;
	if(__gcd(a, b) == 1){
		cout << "Finite" << endl;
	}else{
		cout << "Infinite" << endl;
	}
}
int main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
}