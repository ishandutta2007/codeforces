#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int f[300001],r[300001],dj[300001];
vector<int> g[300001]; 
int resi(int s)
{
	if(g[s].empty())
	{
		r[s]=s;
		dj[s]=1;
		return 1;
	}
	int max=0,t,imax=0,v=0;
	for(int i=0;i<g[s].size();i++)
	{
		t=resi(g[s][i]);
		v+=t;
		if(t>max)
		{
			max=t;
			imax=i;
		}
	}
	v++;
	dj[s]=v;
	if(max<(v+1)/2) r[s]=s;
	else 
	{
		int k=r[g[s][imax]];
		while(dj[k]<(v+1)/2) k=f[k];
		r[s]=k;
	}
	
	return v;
}
int main(int argc, char** argv) 
{
	int n,q,t;
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&t);
		f[i]=t;
		g[t].push_back(i);
	}
	resi(1);
	for(int i=0;i<q;i++)
	{
		scanf("%d",&t);
		printf("%d ",r[t]);
	}
	return 0;
}