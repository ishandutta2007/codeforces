#include <bits/stdc++.h>
using namespace std;


bool check(string a, string b) {
	if (a == b) return 1;
	if (a.size() % 2) return 0;
	return ((check(a.substr(0, a.size()/2), b.substr(0, b.size()/2)) && check(a.substr(a.size()/2, a.size()/2), b.substr(b.size()/2, b.size()/2))) ||
			(check(a.substr(a.size()/2, a.size()/2), b.substr(0, b.size()/2)) && check(a.substr(0, a.size()/2), b.substr(b.size()/2, b.size()/2))));
}

int main() {
      string a, b; 
      cin >> a >> b;
	if (check(a, b)) {cout << "YES";}
	else {cout << "NO";}
	return 0;
}