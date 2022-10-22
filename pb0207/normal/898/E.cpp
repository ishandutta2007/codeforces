#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long ll;

const int N=2e5+1e3+7;

int n;

ll a[N];

struct node{
	int x,y;
}o[N];

bool is(ll x)
{
	ll t=sqrt((double)x+0.5);
	return t*t==x;
}

bool cmp(node a,node b)
{
	return a.x-a.y<b.x-b.y;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]==0)
			o[i].x=0,o[i].y=2;
		else
		{
			ll k=sqrt(double(a[i])+0.5);
			o[i].x=min(a[i]-k*k,(k+1)*(k+1)-a[i]);
			if(!is(a[i]))
				o[i].y=0;
			else
			if((!is(a[i]-1))||(!is(a[i]+1)))
				o[i].y=1;
			else
				o[i].y=2;
		}
	}
	sort(o+1,o+n+1,cmp);
	ll ans=0;
	for(int i=1;i<=n/2;i++)
		ans+=o[i].x;
	for(int i=n/2+1;i<=n;i++)
		ans+=o[i].y;
	printf("%lld",ans);
}