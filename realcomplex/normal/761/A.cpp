#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b;
	cin >> a >> b;
	if(a == 0 && b == 0){
		cout << "NO";
	}
	else{
	if(a > b){
		if(a == b + 1){
			cout << "YES";
		}
		else{
			cout << "NO";
		}
	}
	else{
		if((b == a || b == a + 1)){
			cout << "YES";
		}
		else{
			cout << "NO";
		}
	}
	}
	return 0;
}