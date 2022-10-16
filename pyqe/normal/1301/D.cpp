#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,kd[2][3],zs=0;
vector<long long> kv[2][3];
pair<long long,vector<long long>> sq[3069];
string ky="URDL";

int main()
{
	long long i,j,ii,sz,dd;
	vector<long long> v;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	if(d>(n*m*2-n-m)*2)
	{
		printf("NO\n");
		return 0;
	}
	kv[0][0].push_back(1);
	kv[0][0].push_back(2);
	kv[0][0].push_back(0);
	kv[0][1].push_back(3);
	kv[0][2].push_back(2);
	kv[1][0].push_back(1);
	kv[1][1].push_back(3);
	kv[1][2].push_back(0);
	kd[0][0]=m-1;
	kd[0][1]=m-1;
	kd[0][2]=1;
	kd[1][0]=m-1;
	kd[1][1]=m-1;
	kd[1][2]=n-1;
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<3;ii++)
		{
			v=kv[i==n][ii];
			sz=v.size();
			dd=kd[i==n][ii];
			if(d>=dd*sz)
			{
				if(dd)
				{
					zs++;
					sq[zs]={dd,v};
					d-=dd*sz;
				}
			}
			else
			{
				if(d/sz)
				{
					zs++;
					sq[zs]={d/sz,v};
					d%=sz;
				}
				if(d)
				{
					for(j=0;j<sz-d;v.pop_back(),j++);
					zs++;
					sq[zs]={1,v};
					d=0;
				}
			}
		}
	}
	printf("YES\n%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld ",sq[i].fr);
		sz=sq[i].sc.size();
		for(j=0;j<sz;j++)
		{
			printf("%c",ky[sq[i].sc[j]]);
		}
		printf("\n");
	}
}