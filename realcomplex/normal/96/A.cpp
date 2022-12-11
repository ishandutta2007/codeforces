#include <bits/stdc++.h>
using namespace std;

int main() {
	string n;
	cin >> n;
	if(n.find("0000000") != -1 || n.find("1111111") != -1){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}