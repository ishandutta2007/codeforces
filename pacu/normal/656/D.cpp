#include <iostream>
using namespace std;

int main()
{
	int cnt = 0;
	int a;
	cin >> a;
	while(a)
	{
		if(a%8 == 1) cnt++;
		a /= 8;
	}
	cout << cnt << '\n';
}