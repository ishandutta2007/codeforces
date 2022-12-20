#include <iostream>
using namespace std;

long long s,x;

int main()
{
	cin >> s >> x;
	bool sum2 = 0;
	long long a,b;
	long long ways = 1;
	for(long long i=50;i>=0;i--)
	{
		a = (s>>i)&1LL;
		b = (x>>i)&1LL;
		if(sum2==0)
		{
			if(b==1 && a==1)
				ways *= 2LL;
			else if(b==0 && a==0)
				ways *= 1LL;
			else if(b==1 && a==0)
				ways = 0;
			else if(b==0 && a==1)
				sum2 = 1;
		}
		else
		{
			if(b==1 && a==1)
				ways = 0;
			else if(b==0 && a==0)
				ways *= 1LL, sum2 = 0;
			else if(b==1 && a==0)
				ways *= 2LL, sum2 = 1;
			else if(b==0 && a==1)
				ways *= 1LL, sum2 = 1;
				
		}
	}
	if(sum2 == 1) ways = 0;
	if(s==x) ways -= 2;
	cout << ways << '\n';
}