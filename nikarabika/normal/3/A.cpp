#include <bits/stdc++.h>

using namespace std;

int main(){
	stringstream ss;
	char c1, c2;
	int i1, i2;
	cin >> c1 >> i1 >> c2 >> i2;
	int x = i1, y = c1 - 'a' + 1;
	int xx = i2, yy = c2 - 'a' + 1, ans = 0;
	while(x < xx and y < yy)
		ss << "RU\n", x++, y++, ans++;
	while(x < xx and y > yy)
		ss << "LU\n", x++, y--, ans++;
	while(x > xx and y < yy)
		ss << "RD\n", x--, y++, ans++;
	while(x > xx and y > yy)
		ss << "LD\n", x--, y--, ans++;
	while(x < xx)
		ss << "U\n", x++, ans++;
	while(x > xx)
		ss << "D\n", x--, ans++;
	while(y < yy)
		ss << "R\n", y++, ans++;
	while(y > yy)
		ss << "L\n", y--, ans++;
	cout << ans << endl << ss.str();
	return 0;
}