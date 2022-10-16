#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long pm[9];
pair<long long,long long> a[9],df[5];

int main()
{
	long long i,y,x;
	
	for(i=1;i<=8;i++)
	{
		scanf("%lld%lld",&y,&x);
		a[i]={y,x};
		pm[i]=i;
	}
	for(;1;)
	{
		for(i=1;i<=4;i++)
		{
			df[i]={a[pm[i]].fr-a[pm[i%4+1]].fr,a[pm[i]].sc-a[pm[i%4+1]].sc};
		}
		for(i=1;i<=4;i++)
		{
			if(df[i].fr!=df[i%4+1].sc||df[i].sc!=-df[i%4+1].fr)
			{
				i=-1;
				break;
			}
		}
		if(i!=-1)
		{
			for(i=1;i<=4;i++)
			{
				df[i]={a[pm[i+4]].fr-a[pm[i%4+5]].fr,a[pm[i+4]].sc-a[pm[i%4+5]].sc};
			}
			for(i=1;i<=4;i++)
			{
				if(df[i].fr*-df[i%4+1].fr!=df[i%4+1].sc*df[i].sc||df[i].fr!=-df[(i+1)%4+1].fr||df[i].sc!=-df[(i+1)%4+1].sc)
				{
					i=-1;
					break;
				}
			}
			if(i!=-1)
			{
				printf("YES\n");
				for(i=1;i<=8;i++)
				{
					printf("%lld%c",pm[i]," \n"[i%4==0]);
				}
				return 0;
			}
		}
		if(!next_permutation(pm+1,pm+9))
		{
			break;
		}
	}
	printf("NO\n");
}