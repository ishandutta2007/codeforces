#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const int sqn=547;
int n,nn=0,nm=0,a[300069],dh[300069],peu[300069],lg2[600069],wg[600069],pst[300069],as[300069],sqb[569],sq[300069];
vector<int> al[300069];
bitset<300069> vtd,sqa;
pair<int,int> sp[20][600069];
pair<pair<int,int>,pair<int,int>> qq[300069];

void bd(int x)
{
	int i,sz=al[x].size(),l;
	
	vtd[x]=1;
	nn++;
	sp[0][nn]={dh[x],x};
	peu[x]=nn;
	nm++;
	wg[nm]=a[x];
	pst[x]=nm;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dh[l]=dh[x]+1;
			bd(l);
			nn++;
			sp[0][nn]={dh[x],x};
		}
	}
	nm++;
	wg[nm]=a[x];
}

inline void spbd()
{
	int i,j,k;
	
	for(i=1;1ll<<i<=nn;i++)
	{
		for(j=1;j<=nn-(1ll<<i)+1;j++)
		{
			sp[i][j]=min(sp[i-1][j],sp[i-1][j+(1ll<<i-1)]);
		}
	}
	for(i=1;i<=nn;i++)
	{
		for(k=i;k>1;k/=2,lg2[i]++);
	}
}

inline int spqr(int lh,int rh)
{
	int e=lg2[rh-lh+1];
	
	return min(sp[e][lh],sp[e][rh-(1ll<<e)+1]).sc;
}

inline int lca(int x,int y)
{
	if(peu[x]>peu[y])
	{
		swap(x,y);
	}
	return spqr(peu[x],peu[y]);
}

bool mos(int x,int y)
{
	return mp(pst[qq[x].fr.fr]/sqn,pst[qq[x].fr.sc])<mp(pst[qq[y].fr.fr]/sqn,pst[qq[y].fr.sc]);
}

inline void squd(int x)
{
	sqa[x]=!sqa[x];
	if(sqa[x])
	{
		sqb[x/sqn]++;
	}
	else
	{
		sqb[x/sqn]--;
	}
}

inline int sqqr(int lh,int rh)
{
	int i,j,k;
	
	k=min((lh/sqn+1)*sqn-1,rh);
	for(i=lh;i<=k;i++)
	{
		if(sqa[i])
		{
			return i;
		}
	}
	k=rh/sqn;
	for(i=lh/sqn+1;i<k;i++)
	{
		if(sqb[i])
		{
			for(j=i*sqn;!sqa[j];j++);
			return j;
		}
	}
	for(i=max(rh/sqn*sqn,lh);i<=rh;i++)
	{
		if(sqa[i])
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	int t,rr,i,k,l,lb,rb,pz,lr[2],p[2]={1,0},la;
	
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%d%d",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	bd(1);
	spbd();
	for(rr=1;rr<=t;rr++)
	{
		scanf("%d%d%d%d",&k,&l,&lb,&rb);
		if(pst[k]>pst[l])
		{
			swap(k,l);
		}
		qq[rr]={{k,l},{lb,rb}};
		as[rr]=rr;
	}
	sort(as+1,as+t+1,mos);
	for(rr=1;rr<=t;rr++)
	{
		pz=as[rr];
		k=qq[pz].fr.fr;
		l=qq[pz].fr.sc;
		lb=qq[pz].sc.fr;
		rb=qq[pz].sc.sc;
		lr[0]=pst[k]+1;
		lr[1]=pst[l];
		for(;p[0]>lr[0];p[0]--)
		{
			squd(wg[p[0]-1]);
		}
		for(;p[1]<lr[1];p[1]++)
		{
			squd(wg[p[1]+1]);
		}
		for(;p[0]<lr[0];p[0]++)
		{
			squd(wg[p[0]]);
		}
		for(;p[1]>lr[1];p[1]--)
		{
			squd(wg[p[1]]);
		}
		la=lca(k,l);
		squd(a[la]);
		sq[pz]=sqqr(lb,rb);
		squd(a[la]);
	}
	for(rr=1;rr<=t;rr++)
	{
		printf("%d\n",sq[rr]);
	}
}