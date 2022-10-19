#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 100010
#define SQ 350
using namespace std;
ll n,m,a[N],fre[N],land[N];//fre->steps required to jump out of thr segment; land->the hole balls land in after jumping out of the segment
int main(){
	ll i,st,id,tp,val,x;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		st=0;
		id=i;
		while(id/SQ==i/SQ)
		{
			st++;
			id+=a[id];
			if(id>=n)
			{
				break;
			}
		}
		fre[i]=st;
		land[i]=id;
	}
	while(m--)
	{
		scanf("%lld",&tp);
		if(tp==0)
		{
			scanf("%lld%lld",&x,&val);
			x--;
			a[x]=val;
			st=0;
			id=x;
			while(id/SQ==x/SQ)
			{
				st++;
				id+=a[id];
				if(id>=n)
				{
					break;
				}
			}
			fre[x]=st;
			land[x]=id;
			for(i=x-1;i>=(x/SQ)*SQ;i--)
			{
				if((i+a[i])/SQ>x/SQ||i+a[i]>=n)
				{
					fre[i]=1;
					land[i]=i+a[i];
				}
				else
				{
					fre[i]=fre[i+a[i]]+1;
					land[i]=land[i+a[i]];
				}
			}
		}
		else
		{
			scanf("%lld",&x);
			x--;
			st=0;
			for(i=x;i<n;)
			{
				id=land[i];
				if(id>=n)
				{
					id=i;
					while(id<n)
					{
						id+=a[id];
						st++;
						if(id<n)
						{
							i=id;
						}
					}
					break;
				}
				st+=fre[i];
				i=id;
			}
			printf("%lld %lld\n",i+1,st);
		}
	}
	return 0;
}