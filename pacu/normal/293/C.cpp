#include <iostream>
#include <algorithm>
using namespace std;

int dv[10000000];
int C = 0;

int main()
{
	long long N;
	cin >> N;
	if(N%6)
	{
		cout << 0 << '\n';
		return 0;
	}
	N /= 3;
	long long tmp = N;
	long long tot = 1;
	dv[C++] = 1;
	for(long long i=2;i<=N && i<=10000000;i++)
	{
		if(N%i == 0)
		{
			dv[C++] = i;
			int e = 0;
			while(tmp%i == 0)
			{
				e++;
				tmp /= i;
			}
			int ways = ((e+2)*(e+1))/2;
			if(i==2)
			{
				if(e>=2) ways -= 3*(e-1);
			}
			tot *= ways;
		}
	}
	for(int c=0;c<C && dv[c]<=50000;c++)
	{
		long long x = dv[c];
		for(int d=c;d<C && x*x*dv[d] + (x*dv[d])*dv[d] <= N;d++)
		{
			long long y = dv[d];
			if((N/x)%y == 0)
			{
				if((x+y+(N/(x*y)))%2 == 0)
				{
					tot -= 3*(1+(x!=y));
					//cout << x << ' ' << y << ' ' << N/(x*y) << '\n';
				}
			}
		}
	}
	cout << tot << '\n';
}