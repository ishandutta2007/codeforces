# include <cstdio>
# include <iostream>
# include <cmath>
# include <vector>
# include <set>
# include <algorithm>
# include <queue>

using namespace std;

long long gcd(long long a,long long b)
{
	return (a==0)?b:gcd(b%a,a);
}

long long ar[100];

int main()
{
	long long N;
	cin>>N;

	int cnt=min(100,(int)N);
	for(int i=0;i<cnt;i++)
		ar[i]=N-i;

	long long best=0;
	for(int i=0;i<cnt;i++)
	{
		for(int j=i;j<cnt;j++)
		{
			long long sol=ar[i]*ar[j]/gcd(ar[i],ar[j]);
			for(int k=j;k<cnt;k++)
				best=max(best,sol*ar[k]/gcd(sol,ar[k]));
		}
	}

	cout<<best<<endl;
	return 0;
}