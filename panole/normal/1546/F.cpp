#include<bits/stdc++.h>
using namespace std;

int m,k,x[1010][1010];
long long s1[1010],s2[1010];

int main()
{
	scanf("%d%d",&m,&k);
	for (int i=0; i<k; i++)
	{
		s1[i]=s2[i]=0;
		for (int j=1; j<=m; j++) scanf("%d",&x[i][j]),s1[i]+=x[i][j],s2[i]+=1ll*x[i][j]*x[i][j];
	}
	int p=-1;
	long long kk=(s1[k-1]-s1[0])/(k-1),del,dd;
	for (int i=1; i<k; i++) 
		if (s1[i]!=s1[i-1]+kk) {p=i,del=s1[i]-s1[i-1]-kk; break;}
	assert(p!=-1);
	if (p<3)
	{
		long long a=(s2[5]-s2[4]-(s2[5]-s2[3])/2);
		long long b=s2[3]-9*a-(s2[3]+s2[4]-s2[5]);
		long long c=s2[3]-9*a-3*b;
		dd=s2[p]-(a*p*p+b*p+c);
	} else
	{
		long long c=s2[0];
		long long a=(s2[2]-s2[1]-s2[1]+c)/2;
		long long b=s2[1]-c-a;
		dd=s2[p]-(a*p*p+b*p+c);
	}
	printf("%d %lld\n",p,(dd-del*del)/2/del),fflush(stdout);
	return 0;
}