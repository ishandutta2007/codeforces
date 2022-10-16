#include <bits/stdc++.h>

using namespace std;

long long n,yk[26],a[100069],ps[2][100069];

int main()
{
	long long i,ys,xs,yf,xf,yy,xx,ky[4]={-1,0,1,0},kx[4]={0,1,0,-1},lh,rh,md,zz=-1;
	string s;
	
	yk[3]=0;
	yk[17]=1;
	yk[20]=2;
	yk[11]=3;
	scanf("%lld%lld%lld%lld%lld",&xs,&ys,&xf,&yf,&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=yk[s[i-1]-'A'];
		ps[0][i]=ps[0][i-1]+ky[a[i]];
		ps[1][i]=ps[1][i-1]+kx[a[i]];
	}
	for(lh=0,rh=1e18;lh<=rh;)
	{
		md=(lh+rh)/2;
		yy=ys+ps[0][n]*(md/n)+ps[0][md%n];
		xx=xs+ps[1][n]*(md/n)+ps[1][md%n];
		if(abs(yf-yy)+abs(xf-xx)<=md)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	printf("%lld\n",zz);
}