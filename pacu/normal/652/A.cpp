#include <iostream>
using namespace std;

int main()
{
	long long h1,h2;
	int a,b;
	cin >> h1 >> h2 >> a >> b;
	int ch = 14;
	int d = 0;
	while(1)
	{
		int tmp = h1;
		if(ch < 10 || ch >= 22)
			h1 -= b;
		else
			h1 += a;
		if(h1 >= h2 && ch >= 14)
			break;
		if(ch == 23)
			ch = 0, d++;
		else
			ch++;
		if(d >= 100000)
		{
			cout << -1 << '\n';
			return 0;
		}
//		cout << ch << ' ' << h1 << '\n';
	}
	cout << d << '\n';
	return 0;
}