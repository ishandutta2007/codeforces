#include <iostream>
using namespace std;
int main()
{
	int n,a,b;
	int x;
	int sm;
	cin >> n;
	a = b = 0;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		if(x==100) a++;
		else b++;
	}
	if(a%2) cout << "NO" << endl;
	else
	{
		sm = (a/2) + b;
		for(int xa=0;xa<=a;xa++)
		{
			if((sm-xa)%2) continue;
			if((((sm-xa)/2)<=b)&&(((sm-xa)/2)>=0))
			{cout << "YES"<<endl;return 0;}
		}
		cout << "NO" << endl;
	}
}