#include <bits/stdc++.h>

using namespace std;

const int sqn=316;
int n,a[100069],pc[100069];
vector<int> al[100069];
bitset<100069> spc;

int main()
{
	int t,rr,i,j,k,l,w,sz,sm,z=0;
	vector<int> v;
	char ch;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %c%d",&k,&ch,&l);
		a[i]=100-(k*100+l);
		z+=a[i]*100;
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&k,&l);
		k++;
		l++;
		z-=a[k]*a[l];
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(i=1;i<=n;i++)
	{
		sz=al[i].size();
		spc[i]=sz>sqn;
	}
	for(i=1;i<=n;i++)
	{
		v.clear();
		sz=al[i].size();
		for(j=0;j<sz;j++)
		{
			l=al[i][j];
			if(spc[l])
			{
				if(!spc[i])
				{
					pc[l]+=a[i];
				}
				else
				{
					v.push_back(l);
				}
			}
		}
		if(spc[i])
		{
			al[i]=v;
		}
	}
	scanf("%d",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%d%d %c%d",&k,&l,&ch,&w);
		k++;
		w=100-(l*100+w);
		sm=pc[k];
		sz=al[k].size();
		for(i=0;i<sz;i++)
		{
			l=al[k][i];
			sm+=a[l];
		}
		z+=(w-a[k])*(100-sm);
		if(!spc[i])
		{
			for(i=0;i<sz;i++)
			{
				l=al[k][i];
				if(spc[l])
				{
					pc[l]+=w-a[k];
				}
			}
		}
		a[k]=w;
		printf("%d.",z/10000);
		for(k=z%10000,i=0;k<1000&&i<3;k*=10,i++)
		{
			printf("0");
		}
		printf("%d\n",z%10000);
	}
}