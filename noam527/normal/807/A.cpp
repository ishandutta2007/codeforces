#include <iostream>
using namespace std;

int a[1000], b[1000], n;
bool isInc = true;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
	if (a[0] != b[0])
	{
		cout << "rated" << endl;
		return 0;
	}
	for (int i = 1; i < n; i++)
	{
		if (a[i] != b[i])
		{
			cout << "rated" << endl;
			return 0;
		}
		if (a[i] > a[i - 1])
			isInc = false;
	}
	if (!isInc)
		cout << "unrated" << endl;
	else
		cout << "maybe" << endl;
	return 0;
}