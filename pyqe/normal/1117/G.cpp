#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

int n,a[1000069],pst[1000069],sp[20][1000069],lg2[1000069],mda[1000069],fi;
pair<int,int> rg[1000069],qq[1000069];
pair<pair<int,int>,pair<int,int>> as[2000069];
pair<pair<int,int>,int> qs[1000069];
long long fw[2][1000069],sq[1000069];

inline void spbd()
{
	int i,j,k;
	
	for(i=1;i<=n;i++)
	{
		sp[0][i]=a[i];
	}
	for(i=1;1<<i<=n;i++)
	{
		for(j=1;j<=n-(1<<i)+1;j++)
		{
			sp[i][j]=max(sp[i-1][j],sp[i-1][j+(1<<i-1)]);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(k=i;k>1;k/=2,lg2[i]++);
	}
}

inline int spqr(int lh,int rh)
{
	int e=lg2[rh-lh+1];
	
	return max(sp[e][lh],sp[e][rh-(1<<e)+1]);
}

inline void fwud(int xx,int x,int w)
{
	for(fi=x;fi<=n;fi+=fi&-fi)
	{
		fw[xx][fi]+=w;
	}
}

inline long long fwqr(int xx,int lh,int rh)
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

int main()
{
	int rrr,t,rr,i,ii,k,l,w,lh,rh,md,zz,pz,k2,l2,w2;
	
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		pst[a[i]]=i;
	}
	spbd();
	for(i=1;i<=n;i++)
	{
		for(lh=1,rh=i;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(spqr(md,i)==a[i])
			{
				zz=md;
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		rg[i].fr=zz;
		for(lh=i,rh=n;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(spqr(i,md)==a[i])
			{
				zz=md;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		rg[i].sc=zz;
	}
	for(rr=1;rr<=t;rr++)
	{
		scanf("%d",&qq[rr].fr);
	}
	for(rr=1;rr<=t;rr++)
	{
		scanf("%d",&qq[rr].sc);
		k=qq[rr].fr;
		l=qq[rr].sc;
		sq[rr]=l-k+1;
		mda[rr]=pst[spqr(k,l)];
	}
	for(rrr=0;rrr<2;rrr++)
	{
		for(i=1;i<=n;i++)
		{
			k=rg[i].fr;
			l=rg[i].sc;
			as[i*2-1]={{i,k},{1,-(k-1)}};
			as[i*2]={{l,k},{-1,l}};
		}
		sort(as+1,as+n*2+1);
		for(rr=1;rr<=t;rr++)
		{
			l=qq[rr].sc;
			qs[rr]={{l,mda[rr]+1},rr};
		}
		sort(qs+1,qs+t+1);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				fw[ii][i]=0;
			}
		}
		for(i=1,rr=1;rr<=t;rr++)
		{
			l=qs[rr].fr.fr;
			k=qs[rr].fr.sc;
			pz=qs[rr].sc;
			for(;i<=n*2;i++)
			{
				l2=as[i].fr.fr;
				k2=as[i].fr.sc;
				w=as[i].sc.fr;
				w2=as[i].sc.sc;
				if(l2>l)
				{
					break;
				}
				fwud(0,k2,w);
				fwud(1,k2,w2);
			}
			sq[pz]+=fwqr(0,k,l)*l+fwqr(1,k,l);
		}
		for(i=1;i<n+1-i;i++)
		{
			swap(a[i],a[n+1-i]);
			swap(rg[i],rg[n+1-i]);
		}
		for(i=1;i<=n;i++)
		{
			pst[i]=n+1-pst[i];
			k=rg[i].fr;
			l=rg[i].sc;
			rg[i]={n+1-l,n+1-k};
		}
		for(rr=1;rr<=t;rr++)
		{
			k=qq[rr].fr;
			l=qq[rr].sc;
			qq[rr]={n+1-l,n+1-k};
			mda[rr]=n+1-mda[rr];
		}
	}
	for(rr=1;rr<=t;rr++)
	{
		printf("%lld%c",sq[rr]," \n"[rr==t]);
	}
}