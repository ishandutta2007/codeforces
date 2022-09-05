#include<bits/stdc++.h>
using namespace std;

int n,p,q;
unsigned int a[270],t[270],T[270],ans,nw,res;

int main()
{
	scanf("%d%d%d",&n,&p,&q);
	a[0]=a[1]=1,t[0]=1,p=min(p,n-1);
	for (; n; n>>=1)
	{
		if (n&1)
		{
			memset(T,0,sizeof(T));
			for (int i=0; i<=p; i++)
				for (int j=0; j<=p; j++)
					T[i+j]+=t[i]*a[j];
			memcpy(t,T,sizeof(t));
		}
		memset(T,0,sizeof(T));
		for (int i=0; i<=p; i++)
			for (int j=0; j<=p; j++)
				T[i+j]+=a[i]*a[j];
		memcpy(a,T,sizeof(a));
	}
	res=0;
	for (unsigned int i=1; i<=q; i++)
	{
		nw=1,ans=0;
		for (int j=0; j<=p; j++,nw*=i) ans+=nw*t[j];
		res^=(i*ans);
	}
	printf("%u\n",res);
	return 0;
}