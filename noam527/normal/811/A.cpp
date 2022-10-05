#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int x, y, tx, ty;
	cin >> x >> y;
	tx = (int)sqrt(x), ty = (int)((double)-1 / 2 + sqrt(y + (double)1 / 4));
	//cout << tx << " " << ty << endl;
	if (tx <= ty)
		cout << "Vladik" << endl;
	else
		cout << "Valera" << endl;
}