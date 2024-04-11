#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,a[1069][1069];
bitset<1069> vtd[1069];
queue<pair<pair<long long,long long>,long long>> q;

int main()
{
	long long i,j,ys,xs,yf,xf,y,x,w,yy,xx,im,ky[4]={-1,0,1,0},kx[4]={0,1,0,-1},ds=1e18,z=0;
	string s;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=m;j++)
		{
			if(s[j-1]=='T')
			{
				vtd[i][j]=1;
			}
			else if(s[j-1]=='S')
			{
				ys=i;
				xs=j;
			}
			else if(s[j-1]=='E')
			{
				yf=i;
				xf=j;
			}
			else
			{
				a[i][j]=s[j-1]-'0';
			}
		}
	}
	q.push({{yf,xf},0});
	vtd[yf][xf]=1;
	for(;!q.empty();)
	{
		y=q.front().fr.fr;
		x=q.front().fr.sc;
		w=q.front().sc;
		q.pop();
		if(w>ds)
		{
			break;
		}
		if(y==ys&&x==xs)
		{
			ds=w;
		}
		z+=a[y][x];
		for(im=0;im<4;im++)
		{
			yy=y+ky[im];
			xx=x+kx[im];
			if(yy&&xx&&yy<=n&&xx<=m&&!vtd[yy][xx])
			{
				q.push({{yy,xx},w+1});
				vtd[yy][xx]=1;
			}
		}
	}
	printf("%lld\n",z);
}