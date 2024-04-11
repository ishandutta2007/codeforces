#include <bits/stdc++.h>

using namespace std;

int n,z=0,dv=1e9+7;
bitset<16> spc;
bitset<3069> a;

struct trie
{
	int dh,mk,dp[4];
	trie *p[2];
	
	void bd(int x)
	{
		int i,ii;
		
		dh=x;
		mk=0;
		for(i=0;i<4;i++)
		{
			dp[i]=0;
		}
		for(ii=0;ii<2;ii++)
		{
			p[ii]=0;
		}
	}
	void ins(int x)
	{
		if(dh<x)
		{
			int i,e=a[dh+1];
			
			if(!p[e])
			{
				p[e]=new trie;
				p[e]->bd(dh+1);
				p[e]->mk=(mk<<1|e)%16;
				for(i=3;i;i--)
				{
					p[e]->dp[i]=dp[i-1];
				}
				for(i=0;i<4;i++)
				{
					p[e]->dp[0]=(p[e]->dp[0]+dp[i]*(i<3||!spc[p[e]->mk]))%dv;
				}
				z=(z+p[e]->dp[0])%dv;
			}
			p[e]->ins(x);
		}
	}
}
tr;

int main()
{
	int i,j,k;
	
	spc[7]=1;
	spc[10]=1;
	spc[12]=1;
	spc[15]=1;
	scanf("%d",&n);
	tr.bd(0);
	tr.dp[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(j=i;j-1;j--)
		{
			a[j]=a[j-1];
		}
		a[1]=k;
		tr.ins(i);
		printf("%d\n",z);
	}
}