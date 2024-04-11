#include <bits/stdc++.h>

using namespace std;

int n,m,nn=0,fq[4],vl[4][1<<5],a[5],sk[5],tg[5],sq[21];
short pr[21][21][21][21][21][21];

void fl(int x)
{
	if(nn<n)
	{
		nn++;
		for(sk[nn-1]=0;sk[nn-1]<=m+m%2;sk[nn-1]++)
		{
			fl(x);
		}
		nn--;
	}
	else
	{
		pr[x][sk[0]][sk[1]][sk[2]][sk[3]][sk[4]]=-1;
	}
}

void rk(int x,int w)
{
	if(nn<n)
	{
		nn++;
		for(sk[nn-1]=0;sk[nn-1]<=x;sk[nn-1]++)
		{
			rk(x,w);
		}
		nn--;
	}
	else if(pr[x][sk[0]][sk[1]][sk[2]][sk[3]][sk[4]]+1)
	{
		int i,j,k,mk;
		
		for(i=1;i<=fq[w];i++)
		{
			mk=0;
			for(j=0;j<n;j++)
			{
				k=sk[j]%2!=(vl[w][i]>>j&1);
				mk|=k<<j;
				tg[j]=sk[j]+k;
			}
			pr[x+1][tg[0]][tg[1]][tg[2]][tg[3]][tg[4]]=mk;
		}
	}
}

int main()
{
	int i,j,k,mk,c,e[5]={0,0,0,0,0};
	
	scanf("%d%d",&n,&m);
	for(mk=0;mk<1<<n;mk++)
	{
		c=0;
		for(i=0;i<n;i++)
		{
			c+=(mk>>i&1)&&!(mk>>i+1&1);
		}
		fq[c]++;
		vl[c][fq[c]]=mk;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	for(i=0;i<=m;i++)
	{
		fl(i);
	}
	pr[0][0][0][0][0][0]=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d",&k);
		rk(i-1,k);
	}
	for(mk=0;mk<1<<n;mk++)
	{
		for(i=0;i<n;i++)
		{
			e[i]=a[i]*2-1+(mk>>i&1);
			if(e[i]<0)
			{
				break;
			}
		}
		if(i==n&&pr[m][e[0]][e[1]][e[2]][e[3]][e[4]]+1)
		{
			break;
		}
	}
	for(i=m;i;i--)
	{
		for(j=0;j<n;j++)
		{
			sq[i]|=e[j]%2<<j;
			tg[j]=e[j]-(pr[i][e[0]][e[1]][e[2]][e[3]][e[4]]>>j&1);
		}
		for(j=0;j<n;j++)
		{
			e[j]=tg[j];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=1;j<=m;j++)
		{
			printf("%c",".*"[sq[j]>>i&1]);
		}
		printf("\n");
	}
}