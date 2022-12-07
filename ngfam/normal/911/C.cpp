#include <bits/stdc++.h>

using namespace std;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int a, b, c;

	cin >> a >> b >> c;

	if(min(a, min(b, c)) == 1){
		cout << "YES";
		return 0;
	}

	if((a == 2) + (b == 2) + (c == 2) >= 2){
		cout << "YES";
		return 0;
	}

	if(a == 3 && b == 3 && c == 3){
		cout << "YES";
		return 0;
	}

	if(min(a, min(b, c)) == 2 && max(a, max(b, c)) == 4 && ((a == 4) + (b == 4) + (c == 4)) == 2){
		cout << "YES";
		return 0;
	}

	cout << "NO";

	return 0;
}