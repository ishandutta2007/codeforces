#include <bits/stdc++.h>

using namespace std;

long long n,zs=0;
bitset<569> spc[569],sq;

int main()
{
	long long rr,i,ii,u,ys,xs,y,x,yy,xx;
	string s;
	
	scanf("%lld",&n);
	for(rr=0;rr<2;rr++)
	{
		u=rr*2-1;
		ys=1+(n-1)*rr;
		xs=1+(n-1)*rr;
		y=n-(n-1)*rr;
		x=n-(n-1)*rr;
		for(;abs(y-ys)+abs(x-xs)>n-!rr;y=yy,x=xx)
		{
			spc[y][x]=1;
			for(ii=0;ii<2;ii++)
			{
				yy=y+(!ii^rr)*u;
				xx=x+(ii^rr)*u;
				printf("? %lld %lld %lld %lld\n",min(ys,yy),min(xs,xx),max(ys,yy),max(xs,xx));
				fflush(stdout);
				cin>>s;
				if(s[0]=='Y')
				{
					break;
				}
			}
		}
		spc[y][x]=1;
	}
	for(y=1,x=1;y<n||x<n;y=yy,x=xx)
	{
		for(ii=0;ii<2;ii++)
		{
			yy=y+!ii;
			xx=x+ii;
			if(spc[yy][xx])
			{
				zs++;
				sq[zs]=ii;
				break;
			}
		}
	}
	printf("! ");
	for(i=1;i<=zs;i++)
	{
		printf("%c","DR"[sq[i]]);
	}
	printf("\n");
	fflush(stdout);
}