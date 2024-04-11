#include <bits/stdc++.h>

using namespace std;

int main(){

	string a;
	cin >> a;

	string b = a;
	reverse(b.begin(), b.end());

	cout << a + b;
	
	return 0;
}