#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[369][369],fq[3][2];

int main()
{
	long long t,rr,i,j,ii,e,ee;
	pair<long long,long long> mxe;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<3;i++)
		{
			for(ii=0;ii<2;ii++)
			{
				fq[i][ii]=0;
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf(" %c",&ch);
				a[i][j]=(ch=='O')-(ch=='.');
				if(a[i][j]+1)
				{
					fq[(i+j)%3][a[i][j]]++;
				}
			}
		}
		mxe={0,-1};
		for(i=0;i<3;i++)
		{
			mxe=max(mxe,{fq[i][0]+fq[i][1],i});
		}
		e=mxe.sc;
		ee=fq[(e+1)%3][0]+fq[(e+2)%3][1]<fq[(e+1)%3][1]+fq[(e+2)%3][0];
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if((i+j)%3!=e&&a[i][j]+1)
				{
					a[i][j]=(i+j-e+2)%3^ee;
				}
				printf("%c",".XO"[a[i][j]+1]);
			}
			printf("\n");
		}
	}
}