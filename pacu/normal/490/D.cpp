#include <iostream>
using namespace std;

int cfact(long long x,long long div)
{
	int ans = 0;
	while(!(x%div))
	{
		ans++;
		x /= div;
	}
	return ans;
}

int main()
{
	long long a1,b1,a2,b2;
	cin >> a1 >> b1 >> a2 >> b2;
	int nTwos1,nTwos2,nThrees1,nThrees2;
	nThrees1 = cfact(a1*b1,3);
	nThrees2 = cfact(a2*b2,3);
	int time = 0;
	while(nThrees1 > nThrees2)
	{
		if(!(a1%3))
		{
			a1 /= 3;
			a1 *= 2;
		}
		else if(!(b1%3))
		{
			b1 /= 3;
			b1 *= 2;
		}
		nThrees1--;
		time++;
	}
	while(nThrees1 < nThrees2)
	{
		if(!(a2%3))
		{
			a2 /= 3;
			a2 *= 2;
		}
		else if(!(b2%3))
		{
			b2 /= 3;
			b2 *= 2;
		}
		nThrees2--;
		time++;
	}
	nTwos1 = cfact(a1*b1,2);
	nTwos2 = cfact(a2*b2,2);
	while(nTwos1 > nTwos2)
	{
		if(!(a1%2))
			a1 /= 2;
		else if(!(b1%2))
			b1 /= 2;
		nTwos1--;
		time++;
	}
	while(nTwos1 < nTwos2)
	{
		if(!(a2%2))
			a2 /= 2;
		else if(!(b2%2))
			b2 /= 2;
		nTwos2--;
		time++;
	}
	if((a1*b1)!=(a2*b2))
		cout << -1 << endl;
	else
	{
		cout << time << endl;
		cout << a1 << " " << b1 << endl;
		cout << a2 << " " << b2 << endl;
	}
}