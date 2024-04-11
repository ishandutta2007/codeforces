#include <iostream>
using namespace std;

bool leap(int i)
{
	if(i%400==0) return 1;
	if(i%100==0) return 0;
	if(i%4==0) return 1;
	return 0;
}

int main()
{
	int y;
	cin >> y;
	int dif = 0;
	for(int i=y+1;;i++)
	{
		if(leap(i-1)) dif += 366;
		else dif += 365;
		if(dif%7 == 0 && (leap(y)==leap(i)))
		{
			cout << i << '\n';
			return 0;
		}
	}
}