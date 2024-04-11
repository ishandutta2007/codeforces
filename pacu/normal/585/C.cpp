#include <iostream>
using namespace std;

long long num[1000000];
bool tp[1000000];
int C;

int main()
{
	ios::sync_with_stdio(0);
	long long M,N;
	cin >> M >> N;
	while(M>1 && N>1)
	{
		if(M<N)
		{
			num[C] = N/M;
			tp[C] = 1;
			N %= M;
			C++;
		}
		else if(M>N)
		{
			num[C] = M/N;
			tp[C] = 0;
			M %= N;
			C++;
		}
		else
		{
			cout << "Impossible\n";
			return 0;
		}
	}
	if(M==0 || N==0)
	{
		cout << "Impossible\n";
		return 0;
	}
	if(M>1)
	{
		num[C] = M-1;
		tp[C] = 0;
		C++;
	}
	else
	{
		num[C] = N-1;
		tp[C] = 1;
		C++;
	}
	for(int i=0;i<C;i++)
	{
		cout << num[i] << ((tp[i]==0)?'A':'B');
	}
	cout << '\n';
}