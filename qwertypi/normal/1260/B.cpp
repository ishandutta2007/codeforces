#include <bits/stdc++.h>

using namespace std;

void sub(){
	int a, b;
	cin >> a >> b;
	if((a + b) % 3 != 0){
		cout << "NO" << endl;
		return;
	}
	if(a > 2 * b || b > 2 * a){
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
}
int main(){
	int q;
	cin >> q;
	while(q--){
		sub();
	}
}