#include <iostream>
using namespace std;

int x[4],y[4];
int n;

int abs(int a)
{
	if(a<0) return -a;
	return a;
}

int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> x[i] >> y[i];
	if(n==1)
	{
		cout << -1 <<'\n';
		return 0;
	}
	if(n==2)
	{
		if(x[0]==x[1] || y[0]==y[1])
		{
			cout << -1 << '\n';
			return 0;
		}
		cout << abs(x[0]-x[1])*abs(y[0]-y[1]) << '\n';
	}
	else
	{
		if(x[0]==x[1] || y[0]==y[1])
		{
			if(x[0]==x[2] || y[0]==y[2])
				cout << abs(x[1]-x[2])*abs(y[1]-y[2]) << '\n';
			else
				cout << abs(x[0]-x[2])*abs(y[0]-y[2]) << '\n';
		}
		else
			cout << abs(x[0]-x[1])*abs(y[0]-y[1]) << '\n';
	}
}