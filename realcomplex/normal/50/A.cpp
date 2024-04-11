#include <iostream>
using namespace std;

int main() {
	
	int h,w;
	cin >> h >> w;
	int v1;
	v1 = h * (w / 2);
	v1 += (w % 2) * (h / 2);
	int v2;
	v2 = w * (h / 2);
	v2 += (h % 2) * (w / 2);
	cout << max(v1,v2);
	return 0;
}