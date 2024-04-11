#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const int ma=300,dv=1e9+7;
int n,nn=0,ex[69],fi,pwk,sq[200069],zs=0;
bitset<369> vtd;
pair<int,pair<pair<int,int>,int>> qq[600069];
long long fw[2][400069];

int pw(int x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=(long long)pwk*pwk%dv;
	if(y%2)
	{
		pwk=(long long)pwk*x%dv;
	}
	return pwk;
}

void ud(int xx,int x,int w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[xx][fi]+=w;
	}
}

long long qr(int xx,int lh,int rh)
{
	long long z=0;
	
	for(fi=rh;fi;fi-=fi&-fi)
	{
		z+=fw[xx][fi];
	}
	for(fi=lh-1;fi;fi-=fi&-fi)
	{
		z-=fw[xx][fi];
	}
	return z;
}

void ud2(int lh,int rh,int w)
{
	ud(0,lh,w);
	ud(1,lh,w*(n+1-lh));
	ud(0,rh+1,-w);
	ud(1,rh+1,-w*(n-rh));
}

long long qr2(int lh,int rh)
{
	return qr(0,1,lh-1)*(rh-lh+1)+qr(1,lh,rh)-qr(0,lh,rh)*(n-rh);
}

int main()
{
	int t,rr,i,j,ii,ky,k,l,w,c,pz;
	long long ww;
	char ch;
	
	for(i=2;i<=ma;i++)
	{
		if(!vtd[i])
		{
			nn++;
			ex[nn]=i;
			for(j=i*i;j<=ma;j+=i)
			{
				vtd[j]=1;
			}
		}
	}
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		qq[i]={1,{{i,i},k}};
	}
	for(rr=1;rr<=t;rr++)
	{
		for(i=0;i<7;i++)
		{
			scanf(" %c",&ch);
		}
		if(ch=='L')
		{
			scanf(" %c%d%d%d",&ch,&k,&l,&w);
			qq[n+rr]={1,{{k,l},w}};
		}
		else
		{
			scanf("%d%d",&k,&l);
			qq[n+rr]={2,{{k,l},0}};
			zs++;
			sq[zs]=1;
		}
	}
	for(i=1;i<=nn;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			for(j=1;j<=n;j++)
			{
				fw[ii][j]=0;
			}
		}
		pz=0;
		for(rr=1;rr<=n+t;rr++)
		{
			ky=qq[rr].fr;
			k=qq[rr].sc.fr.fr;
			l=qq[rr].sc.fr.sc;
			w=qq[rr].sc.sc;
			if(ky==1)
			{
				for(c=0;w%ex[i]==0;w/=ex[i],c++);
				if(c)
				{
					ud2(k,l,c);
				}
			}
			else
			{
				pz++;
				ww=qr2(k,l);
				if(ww)
				{
					sq[pz]=(long long)sq[pz]*pw(ex[i],ww-1)%dv*(ex[i]-1)%dv;
				}
			}
		}
	}
	for(i=1;i<=zs;i++)
	{
		printf("%d\n",sq[i]);
	}
}