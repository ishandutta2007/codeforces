#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int x, y, z, t;
int answ = 0;
//
void pr(int x, int y, int z) {
	if ((x+y >z)&&(x+z>y)&&(y+z>x)) {
		answ = 2;
	} else {
		if (((x+y==z)||(x+z==y)||(y+z==x))&&(answ<2)) answ = 1;
	}
}
//
int main() {
	//freopen("input.txt", "r", stdin);
	cin >> x >> y >> z>> t;
	pr(x, y, z);
	pr(x, y, t);
	pr(x, z, t);
	pr(y, z, t);
	if (answ == 0) cout << "IMPOSSIBLE" << endl; else
	if (answ == 1) cout << "SEGMENT" << endl; else
	if (answ == 2) cout << "TRIANGLE" << endl;
	//
	return 0;
}