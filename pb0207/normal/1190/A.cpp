#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

ll n,m,k;

ll p[N];

int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%lld",&p[i]),p[i]--;
	int x=1,ans=0;
	ll dlt=0;
	while(x<=m)
	{
		int pos=(p[x]-dlt)/k;
		int l=x,r=m+1;
		while(r-l>1)
		{
			int mid=(l+r)>>1;
			if((p[mid]-dlt)/k==pos)
				l=mid;
			else
				r=mid;
		}
		ans++;
		dlt+=(l-x+1);
		x=l+1;
	}
	printf("%d",ans);
}