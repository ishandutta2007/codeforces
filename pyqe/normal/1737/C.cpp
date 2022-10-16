#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
pair<long long,long long> a[3];

int main()
{
	long long t,rr,i,im,y,x,yf,xf;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<3;i++)
		{
			scanf("%lld%lld",&y,&x);
			a[i]={y,x};
		}
		sort(a,a+3);
		scanf("%lld%lld",&yf,&xf);
		for(im=0;im<4;im++)
		{
			if(a[0]==mp(1ll,1ll)&&a[1]==mp(1ll,2ll)&&a[2]==mp(2ll,1ll)&&yf>1&&xf>1)
			{
				break;
			}
			for(i=0;i<3;i++)
			{
				y=a[i].fr;
				x=a[i].sc;
				a[i]={x,n+1-y};
			}
			sort(a,a+3);
			yf=n+1-yf;
			swap(xf,yf);
		}
		for(i=0;i<3;i++)
		{
			y=a[i].fr;
			x=a[i].sc;
			if(yf%2==y%2&&xf%2==x%2)
			{
				break;
			}
		}
		if(im<4||i>=3)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}