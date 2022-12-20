#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<int> bad;

bool prime[35000];
vector<int> primes;
int isBad[35000];

int A[5000];
int totp[5000],badp[5000];
int gval[5000];

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	int N,M;
	cin >> N >> M;
	for(int i=0;i<N;i++)
		cin >> A[i];
	int b;
	for(int j=0;j<M;j++)
	{
		cin >> b;
		bad.insert(b);
	}
	for(int i=2;i<35000;i++)
		prime[i] = 1;
	for(int i=2;i<35000;i++)
		if(prime[i])
		{
			for(int j=i+i;j<35000;j+=i)
				prime[j] = 0;
			primes.push_back(i);
			if(bad.find(i) != bad.end())
				isBad[i] = 1;
		}
	int origAns = 0;
	for(int i=0;i<N;i++)
	{
		int a = A[i];
		int c;
		for(int j=0;j<primes.size();j++)
		{
			c = primes[j];
			while(!(a%c))
			{
				if(isBad[c])
					origAns--;
				else
					origAns++;
				a /= c;
			}
		}
		if(a>1)
		{
			if(bad.find(a) != bad.end())
				origAns--;
			else
				origAns++;
		}
	}
//	cout << origAns << '\n';
	gval[0] = A[0];
	for(int i=1;i<N;i++)
		gval[i] = gcd(A[i],gval[i-1]);
	int factor = 1;
	for(int i=N-1;i>=0;i--)
	{
		if((i<(N-1))&&(gval[i]==gval[i+1]))
			continue;
		int a = gval[i]/factor;
		int c;
		int contrib = 0;
		for(int j=0;j<primes.size();j++)
		{
			c = primes[j];
			while(!(a%c))
			{
				if(isBad[c])
					contrib--;
				else
					contrib++;
				a /= c;
			}
		}
		if(a>1)
		{
			if(bad.find(a) != bad.end())
				contrib--;
			else
				contrib++;
		}
		if(contrib < 0)
		{
			origAns -= contrib*(i+1);
			factor = gval[i];
		}
	}
	cout << origAns << '\n';
}