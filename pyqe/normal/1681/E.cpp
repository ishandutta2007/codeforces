#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,fq[100069],nr[17][2][400069];
pair<long long,long long> a[100069][2];
pair<pair<long long,long long>,long long> vl[100069][4];
vector<pair<long long,long long>> al[400069];
priority_queue<pair<long long,long long>> pq;

bool cmp(pair<pair<long long,long long>,long long> p,pair<pair<long long,long long>,long long> p2)
{
	return p.fr.sc-p.fr.fr<p2.fr.sc-p2.fr.fr;
}

void dnc(long long cdh,long long lb,long long rb)
{
	if(lb<rb)
	{
		long long i,ii,k,l,w,sz,ww,md=(lb+rb)/2,lb2,rb2;
		
		lb2=max(lb*4-5,1ll);
		rb2=min(rb*4-2,(n-1)*4);
		for(ii=0;ii<2;ii++)
		{
			for(i=lb2;i<=rb2;i++)
			{
				nr[cdh][ii][i]=inf;
			}
			k=md*4-3+ii;
			pq.push({0,k});
			nr[cdh][ii][k]=0;
			k=md*4-1+ii;
			pq.push({0,k});
			nr[cdh][ii][k]=0;
			for(;!pq.empty();)
			{
				w=-pq.top().fr;
				k=pq.top().sc;
				pq.pop();
				if(w>nr[cdh][ii][k])
				{
					continue;
				}
				sz=al[k].size();
				for(i=0;i<sz;i++)
				{
					l=al[k][i].fr;
					ww=al[k][i].sc;
					if(l>=lb2&&l<=rb2&&w+ww<nr[cdh][ii][l])
					{
						pq.push({-w-ww,l});
						nr[cdh][ii][l]=w+ww;
					}
				}
			}
		}
		dnc(cdh+1,lb,md);
		dnc(cdh+1,md+1,rb);
	}
}

long long qr(long long cdh,long long lb,long long rb,long long y,long long x,long long y2,long long x2)
{
	long long i,ii,k,l,p,y3,x3,sm,mn,md=(lb+rb)/2,z;
	
	k=max(y,x);
	l=max(y2,x2);
	if(md>=k&&md<l)
	{
		z=inf;
		for(ii=0;ii<2;ii++)
		{
			sm=1;
			mn=inf;
			for(i=0;i<fq[k];i++)
			{
				y3=vl[k][i].fr.fr;
				x3=vl[k][i].fr.sc;
				p=vl[k][i].sc;
				mn=min(mn,abs(y-y3)+abs(x-x3)+nr[cdh][ii][p]);
			}
			sm+=mn;
			mn=inf;
			for(i=0;i<fq[l];i++)
			{
				y3=vl[l][i].fr.fr;
				x3=vl[l][i].fr.sc;
				p=vl[l][i].sc;
				mn=min(mn,abs(y2-y3)+abs(x2-x3)+nr[cdh][ii][p]);
			}
			sm+=mn;
			z=min(z,sm);
		}
		return z;
	}
	else if(md>=l)
	{
		return qr(cdh+1,lb,md,y,x,y2,x2);
	}
	else
	{
		return qr(cdh+1,md+1,rb,y,x,y2,x2);
	}
}

int main()
{
	long long t,rr,i,j,ii,k,l,w,y,x,y2,x2;
	
	scanf("%lld",&n);
	for(i=1;i<n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld%lld",&y,&x);
			a[i][ii]={y,x};
			k=i*4-3+ii;
			l=i*4-1+ii;
			al[k].push_back({l,1});
			al[l].push_back({k,1});
			vl[i][fq[i]]={{y,x},k};
			fq[i]++;
			vl[i+1][fq[i+1]]={{y+!ii,x+ii},l};
			fq[i+1]++;
		}
	}
	for(i=1;i<=n;i++)
	{
		sort(vl[i],vl[i]+fq[i],cmp);
		for(j=0;j<fq[i];j++)
		{
			y=vl[i][j].fr.fr;
			x=vl[i][j].fr.sc;
			k=vl[i][j].sc;
			if(j)
			{
				w=abs(y-y2)+abs(x-x2);
				al[k].push_back({l,w});
				al[l].push_back({k,w});
			}
			y2=y;
			x2=x;
			l=k;
		}
	}
	dnc(0,1,n);
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&y,&x,&y2,&x2);
		k=max(y,x);
		l=max(y2,x2);
		if(k==l)
		{
			printf("%lld\n",abs(y-y2)+abs(x-x2));
			continue;
		}
		if(k>l)
		{
			swap(y,y2);
			swap(x,x2);
			swap(k,l);
		}
		printf("%lld\n",qr(0,1,n,y,x,y2,x2));
	}
}