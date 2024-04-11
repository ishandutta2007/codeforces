#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

int n,d=22,nn=0,nm,pr[500069],a[500069],fq[1<<22],ps[(1<<22)+1],vl[500069],dh[500069],pst[500069],lg2[1000069],sk[500069],fh[500069][2],sq[500069];
vector<int> al[500069];
pair<int,int> sp[20][1000069];

void dfs(int x)
{
	int i,sz=al[x].size(),l;
	
	fq[a[x]]++;
	vl[ps[a[x]]+fq[a[x]]]=x;
	nn++;
	sp[0][nn]={dh[x],x};
	pst[x]=nn;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		dh[l]=dh[x]+1;
		dfs(l);
		nn++;
		sp[0][nn]={dh[x],x};
	}
}

void spbd()
{
	int i,j,k;
	
	for(i=1;1<<i<=nn;i++)
	{
		for(j=1;j<=nn-(1<<i)+1;j++)
		{
			sp[i][j]=min(sp[i-1][j],sp[i-1][j+(1<<i-1)]);
		}
	}
	for(i=1;i<=nn;i++)
	{
		for(k=i;k>1;k/=2,lg2[i]++);
	}
}

int qr(int lh,int rh)
{
	int e=lg2[rh-lh+1];
	
	return min(sp[e][lh],sp[e][rh-(1<<e)+1]).sc;
}

int lca(int x,int y)
{
	if(pst[x]>pst[y])
	{
		swap(x,y);
	}
	return qr(pst[x],pst[y]);
}

void ad(int x,int w)
{
	int ii,l;
	
	for(;nm>=2&&dh[lca(sk[nm],sk[nm-1])]>=dh[lca(x,sk[nm])];)
	{
		nm--;
		l=lca(sk[nm],sk[nm+1]);
		sk[nm]=l;
		for(ii=0;ii<2;ii++)
		{
			sq[l]=max(sq[l],fh[nm][ii]+fh[nm+1][!ii]-dh[l]*2);
			fh[nm][ii]=max(fh[nm][ii],fh[nm+1][ii]);
		}
	}
	nm++;
	sk[nm]=x;
	fh[nm][w]=dh[x];
	fh[nm][!w]=0;
}

int main()
{
	int i,j,r,k,mk,mkk;
	char ch;
	
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
		scanf("%d %c",pr+i,&ch);
		k=ch-'a';
		a[i]=a[pr[i]]^1<<k;
		al[pr[i]].push_back(i);
	}
	for(i=1;i<=n;i++)
	{
		fq[a[i]]++;
	}
	for(mk=1;mk<=1<<d;mk++)
	{
		ps[mk]=ps[mk-1]+fq[mk-1];
		fq[mk-1]=0;
	}
	dfs(1);
	spbd();
	for(mk=0;mk<1<<d;mk++)
	{
		if(fq[mk])
		{
			for(i=0;i<=d;i++)
			{
				mkk=mk^(int)(i<d)<<i;
				if(mkk>=mk&&fq[mkk])
				{
					nm=0;
					for(r=ps[mkk]+1,j=ps[mk]+1;j<=ps[mk+1]+1;j++)
					{
						for(;r<=ps[mkk+1]&&(j>ps[mk+1]||pst[vl[r]]<pst[vl[j]]);r++)
						{
							ad(vl[r],1);
						}
						if(j<=ps[mk+1])
						{
							ad(vl[j],0);
						}
					}
					ad(1,0);
				}
			}
		}
	}
	for(i=n;i-1;i--)
	{
		sq[pr[i]]=max(sq[pr[i]],sq[i]);
	}
	for(i=1;i<=n;i++)
	{
		printf("%d%c",sq[i]," \n"[i==n]);
	}
}