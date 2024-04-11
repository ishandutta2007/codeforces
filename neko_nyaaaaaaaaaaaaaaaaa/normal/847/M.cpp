#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	int dif = b - a;
	int isokay = true;
	for (int i = 2; i < n; i++)
	{
		a = b;
		cin >> b;
		if (dif != b - a)
			isokay = false;
	}
	if (isokay)
		cout << b + dif << endl;
	else
		cout << b << endl;
	return 0;
}