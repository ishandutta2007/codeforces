#include <iostream>
#include <set>
using namespace std;

int A[1000000];
long long cst[1000000];
long long s[1000000];

long long a,b;

set<int> pr;

void add(int val)
{
	int tmp = val;
	for(int i=2;i*i<=val;i++)
	{
		if(!(tmp%i))
		{
			pr.insert(i);
			while(!(tmp%i))
				tmp /= i;
		}
	}
	if(tmp>1)
		pr.insert(tmp);	
}

int main()
{
	int N;
	cin >> N >> a >> b;
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int j=0;j<N;j++)
	{
		if(j!=0 && j!=N-1) continue;
		add(A[j]);
		add(A[j]-1);
		add(A[j]+1);
	}
	int p;
	long long best = 10000000000000000LL;
	for(set<int>::iterator it=pr.begin();it!=pr.end();it++)
	{
		p = *it;
		int mod;
		for(int i=0;i<N;i++)
		{
			mod = A[i]%p;
			if(mod == 0) cst[i] = 0;
			else if(mod==1 || mod==p-1) cst[i] = b;
			else
				cst[i] = 10000000000LL;
		}
		for(int i=1;i<N;i++)
			s[i] = s[i-1]+cst[i-1];
		best = min(best,s[N-1]+cst[N-1]);
		long long low = 10000000000000000LL;
		long long low2 = 10000000000000000LL;
		for(int i=0;i<N;i++)
		{
			low = min(low,s[i]-a*i);
			if(i>0) low2 = min(low2,s[i]-a*i);
			if(i<N-1)
			{
				best = min(best,low+a*(i+1)+s[N-1]+cst[N-1]-s[i]-cst[i]);
			}
			else
				best = min(best,low2+a*(i+1)+s[N-1]+cst[N-1]-s[i]-cst[i]);
		}
	}
	cout << best << '\n';
}