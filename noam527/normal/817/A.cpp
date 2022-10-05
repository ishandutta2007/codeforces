#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int x1, y1, x2, y2, d1, d2;
	cin >> x1 >> y1 >> x2 >> y2 >> d1 >> d2;
	if (abs(x1 - x2) % d1 != 0 || abs(y1 - y2) % d2 != 0)
		cout << "NO" << endl;
	else if ((abs(x1 - x2) / d1 - abs(y1 - y2) / d2) % 2 != 0)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
}