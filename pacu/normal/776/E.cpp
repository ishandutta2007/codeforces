#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007

bool prime[1000001];

int main()
{
	vector<int> pl;
	for(int i=2;i<=1000000;i++)
		prime[i] = 1;
	for(int i=2;i<=1000000;i++) if(prime[i])
	{
		pl.push_back(i);
		for(int j=2*i;j<=1000000;j+=i)
			prime[j] = 0;
	}
	long long N,K;
	cin >> N >> K;
	K = (K+1)/2;
	for(int k=0;k<K;k++)
	{
		long long cN = N;
		long long dN = N;
		vector<int> pdivs;
		for(int i=0;i<pl.size();i++)
			if(cN%pl[i]==0)
			{
				dN /= pl[i];
				dN *= (pl[i]-1);
				while(cN%pl[i]==0)
					cN /= pl[i];
			}
		if(cN > 1)
		{
			dN /= cN;
			dN *= (cN-1);
		}
		N = dN;
		if(N==1)
			break;
	}
	cout << N%MOD << '\n';
}