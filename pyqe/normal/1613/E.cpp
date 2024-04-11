#include <bits/stdc++.h>

using namespace std;

const long long vy[4]={-1,0,1,0},vx[4]={0,1,0,-1};
long long n,m,st,dg[1000069];
bitset<1000069> a,vtd;
queue<long long> q;

void chk(long long p)
{
	if(dg[p]<=1)
	{
		vtd[p]=1;
		q.push(p);
	}
}

int main()
{
	long long t,rr,i,j,im,y,x,p,yy,xx,pp;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf(" %c",&ch);
				p=i*m+j;
				a[p]=ch=='#';
				if(ch=='L')
				{
					st=p;
				}
				vtd[p]=0;
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				p=i*m+j;
				dg[p]=0;
				for(im=0;im<4;im++)
				{
					yy=i+vy[im];
					xx=j+vx[im];
					pp=yy*m+xx;
					dg[p]+=yy>=0&&xx>=0&&yy<n&&xx<m&&!a[pp];
				}
			}
		}
		dg[st]=0;
		chk(st);
		for(;!q.empty();)
		{
			p=q.front();
			q.pop();
			y=p/m;
			x=p%m;
			for(im=0;im<4;im++)
			{
				yy=y+vy[im];
				xx=x+vx[im];
				pp=yy*m+xx;
				if(yy>=0&&xx>=0&&yy<n&&xx<m&&!a[pp]&&!vtd[pp])
				{
					dg[pp]--;
					chk(pp);
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				p=i*m+j;
				if(p==st)
				{
					printf("L");
				}
				else if(a[p])
				{
					printf("#");
				}
				else
				{
					printf("%c",".+"[vtd[p]]);
				}
			}
			printf("\n");
		}
	}
}