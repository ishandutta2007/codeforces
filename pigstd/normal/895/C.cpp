#include<bits/stdc++.h>
#define int long long
using namespace std;

const int Mod=1e9+7;
const int M=1e5+10;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
int sump=19,kk,n;
int jd[M];

int len(int a)
{
	int ans=0;
	while(a)
		ans++,a/=2;
	return ans;
}

signed main()
{
	cin>>n;kk=n;
	for (int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		int k=0;
		for (int i=0;i<sump;i++)
			if (a%prime[i]==0)
			{
				int sum=0;
				while(a%prime[i]==0)
					a/=prime[i],sum++;
				sum%=2;
				k+=sum*(1<<i);
			} 
		while(jd[len(k)]!=0&&k!=0)
			k^=jd[len(k)];
		if (k!=0)
			kk--,jd[len(k)]=k;
	}
	int ans=1;
	for (int i=1;i<=kk;i++)
		ans=(ans*2)%Mod;
	cout<<ans-1;
	return 0;
}