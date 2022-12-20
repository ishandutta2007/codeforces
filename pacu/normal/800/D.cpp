#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000007

int N;
int A[1000000];

int sum0[1000000],sum1[1000000],sum2[1000000];
int g[1000000];
int sumg[1000000];

int pw[] = {1,10,100,1000,10000,100000};
int inc[1<<6];
int mult[1<<6];
int pw2[1000000];

void add(int &a,int b)
{
	a += b;
	if(a<0) a += MOD;
	if(a>=MOD) a -= MOD;
}

int main()
{
	pw2[0] = 1;
	for(int i=1;i<1000000;i++)
		pw2[i] = (2*pw2[i-1])%MOD;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		sum0[A[i]] = (sum0[A[i]]+1)%MOD;
		sum1[A[i]] = (sum1[A[i]]+A[i])%MOD;
		sum2[A[i]] = (sum2[A[i]]+(A[i]*((long long)A[i])))%MOD;
	}
	for(int i=1;i<(1<<6);i++)
	{
		mult[i] = -1;
		for(int j=0;j<6;j++)
			if(i&(1<<j))
				inc[i] += pw[j], mult[i] *= -1;
	}
	for(int i=999999;i>=0;i--)
	{
		int mask = 0;
		int j = i;
		for(int k=0;k<6;k++)
		{
			if(j%10<9) mask |= (1<<k);
			j /= 10;
		}
//		if(i==123) cout << sum0[i] << '\n';
		for(int m=1;m<(1<<6);m++)
			if((mask|m)==mask)
			{
	//			if(i==123) cout << i+inc[m] << ' ' << mult[m] << ": " << sum0[i+inc[m]] << '\n';
				add(sum0[i],mult[m]*sum0[i+inc[m]]);
				add(sum1[i],mult[m]*sum1[i+inc[m]]);
				add(sum2[i],mult[m]*sum2[i+inc[m]]);
			}
		if(sum0[i]<=1) sumg[i] = sum2[i];
		else
		{
			int pmult = pw2[sum0[i]-2];
			sumg[i] = (((long long)pmult)*((sum2[i] + sum1[i]*((long long)sum1[i]))%MOD))%MOD;
		}
		g[i] = sumg[i];
		for(int m=1;m<(1<<6);m++)
			if((mask|m)==mask)
			{
				add(g[i],-mult[m]*sumg[i+inc[m]]);
			}
//		if(i==123) cout << sum0[i] << '\n';
	}
	long long ans = 0;
	for(int i=0;i<1000000;i++)
		ans ^= i*((long long)g[i]);
	cout << ans << '\n';
}