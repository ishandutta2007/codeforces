#include <iostream>
using namespace std;

int main()
{
	long long N,D,M,L;
	cin >> N >> D >> M >> L;
	long long dif = 0;
	for(long long i=0;;i+=D)
	{
		if((i > (N-1)*M+L)||((i%M)>L))
		{
			cout << i << '\n';
			return 0;
		}
		if(i%M == 0 && i>0)
		{
			dif = i;
			while(i + dif < (N-1)*M + L)
				i += dif;
		}
	}
}