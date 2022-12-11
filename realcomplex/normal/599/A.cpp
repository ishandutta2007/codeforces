#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c;
	cin >> a >> b >> c;
	cout << min(a + b + c,min((a+c)*2,min((a+b)*2,(b+c)*2)));
	return 0;
}