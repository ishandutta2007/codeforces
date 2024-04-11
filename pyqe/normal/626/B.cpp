#include <bits/stdc++.h>

using namespace std;

long long n,d[3],dp[269][269][269],k;
map<char,long long> ky;
string ks="BGR";

long long bf(long long a[3])
{
	if(dp[a[0]][a[1]][a[2]]==0)
	{
		long long i;
		
		for(i=0;i<3;i++)
		{
			if(a[i]>=2)
			{
				a[i]--;
				k=bf(a);
				a[i]++;
				dp[a[0]][a[1]][a[2]]|=k;
			}
			if(a[i]>=1&&a[(i+1)%3]>=1)
			{
				a[i]--;
				a[(i+1)%3]--;
				a[(i+2)%3]++;
				k=bf(a);
				a[i]++;
				a[(i+1)%3]++;
				a[(i+2)%3]--;
				dp[a[0]][a[1]][a[2]]|=k;
			}
		}
	}
	return dp[a[0]][a[1]][a[2]];
}

int main()
{
	long long i,p2,p0,kk;
	string s;
	
	ky['B']=0;
	ky['G']=1;
	ky['R']=2;
	dp[1][0][0]=1;
	dp[0][1][0]=2;
	dp[0][0][1]=4;
	scanf("%lld",&n);
	cin>>s;
	for(i=0;i<n;i++)
	{
		d[ky[s[i]]]++;
	}
	kk=bf(d);
	for(i=0;i<3;i++)
	{
		if(kk%2==1)
		{
			printf("%c",ks[i]);
		}
		kk/=2;
	}
	printf("\n");
}