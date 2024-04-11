#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> primes;

void getprimes()
{
	for(int i=2;i<=100000;i++)
	{
		int j;
		for(j=0;j<primes.size();j++)
		{
			if((j*j) > i)
				break;
			if(!(i%primes[j]))
			{
				j = -1;
				break;
			}
		}
		if(j>-1)
			primes.push_back(i);
	}
}

int best;
int pbest[9592];
int A[100000];

int main()
{
	getprimes();
	int N;
	cin >> N;
	best = 0;
	for(int i=0;i<9592;i++)
		pbest[i] = 0;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		int b = A[i];
		int curbest = 1;
		for(int d=0;(primes[d]*primes[d])<=A[i];d++)
		{
			if(!(b%primes[d]))
				curbest = max(curbest,1 + pbest[d]);
			while(!(b%primes[d]))
				b /= primes[d];
		}
		int left = lower_bound(primes.begin(),primes.end(),b)-primes.begin();
		if(b > 1)
			curbest = max(curbest,1 + pbest[left]);
		b = A[i];
		for(int d=0;(primes[d]*primes[d])<=A[i];d++)
		{
			if(!(b%primes[d]))
				pbest[d] = max(pbest[d],curbest);
			while(!(b%primes[d]))
				b /= primes[d];
		}
		if(b > 1)
			pbest[left] = max(pbest[left],curbest);
		best = max(best,curbest);
	}
	cout << best << endl;
}