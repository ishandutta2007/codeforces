#include <iostream>
using namespace std;

int main()
{
	int x1,y1,x2,y2;
	int x,y;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> x >> y;
	int dx = (x2-x1);
	int dy = (y2-y1);
	if(dx%x || dy%y)
	{
		cout << "NO\n";
		return 0;
	}
	dx /= x;
	dy /= y;
	if((dx+dy)%2)
		cout << "NO\n";
	else
		cout << "YES\n";
}