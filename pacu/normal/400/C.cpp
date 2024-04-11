#include <iostream>
using namespace std;

int N,M;

void transform(int &y,int &x,int clockwise,int rot,int counter,int n,int m)
{
	clockwise %= 4;
	rot %= 2;
	counter %= 4;
	counter = 4-counter;

	for(int i=0;i<clockwise;i++)
	{
		int temp = y;
		y = x;
		x = n+1-temp;

		temp = m;
		m = n;
		n = temp;
	}
	if(rot)
	{
		x = m+1-x;
	}
	for(int i=0;i<counter;i++)
	{
		int temp = y;
		y = x;
		x = n+1-temp;

		temp = m;
		m = n;
		n = temp;
	}
}

int main()
{
	int X,Y,Z;
	int x,y;
	int P;
	cin >> N >> M >> X >> Y >> Z >> P;
	for(int i=0;i<P;i++)
	{
		cin >> x >> y;
		transform(x,y,X,Y,Z,N,M);
		cout << x << " " << y << endl;
	}
}