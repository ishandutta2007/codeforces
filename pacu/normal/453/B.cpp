#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N;

int gcd(int a,int b)
{
	if(a==0)
		return b;
	if(a==1)
		return 1;
	return gcd(b%a,a);
}

int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int fact[60];
int dp[101][(1<<16)];
int cn[101][(1<<16)];

const int mx = 59;
const int nprimes = 16;
const int infinity = (1<<20);

int main()
{
	int i,j,k;
	int N;
	vector<int> A;
	cin >> N;
	for(i=0;i<N;i++)
	{
		A.push_back(0);
		cin >> A[i];
	}
	for(i=1;i<mx;i++)
	{
		fact[i] = 0;
		for(j=0;j<nprimes;j++)
			if(!(i%primes[j]))
				fact[i] |= (1<<j);
	}
	for(i=0;i<=100;i++)
		for(j=0;j<(1<<16);j++)
			dp[i][j] = infinity;
	dp[0][0] = 0;
	int s,x;
	for(i=1;i<=N;i++)
	{
		for(k=1;k<mx;k++)
		{
			x = (~fact[k])&((1<<16)-1);
			for(s=x;;s=(s-1)&x)
			{
				if((dp[i-1][s]+abs(A[i-1]-k)) < dp[i][s | fact[k]])
				{
					dp[i][s|fact[k]] = dp[i-1][s]+abs(A[i-1]-k);
					cn[i][s|fact[k]] = k;
				}
				if(s==0)
					break;
			}
		}
	}
	int mn = infinity;
	for(x=0;x<(1<<16);x++)
		if(dp[N][x]<=mn)
		{
			mn = dp[N][x];
			s = x;
		}
	vector<int> ans;
	for(i=N;i>0;i--)
	{
		ans.push_back(cn[i][s]);
		s = s & ~fact[cn[i][s]];
	}
	for(i=(N-1);i>=0;i--)
		cout << ans[i] << " ";
}