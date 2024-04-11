#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long ma=20,ma2=360,vy[4]={-1,0,1,0},vx[4]={0,-1,0,1};
long long n,ca[3];
bitset<769> a[69];
queue<pair<long long,long long>> q;

int main()
{
	long long t,rr,i,j,im,y,x,yy,xx;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<=ma*2;i++)
		{
			a[i].reset();
		}
		for(i=0;i<n;i++)
		{
			scanf(" %c%lld%lld%lld",&ch,ca,ca+1,ca+2);
			if(ch=='C')
			{
				for(j=ca[1]*2+1;1;j=(j+1)%(ma2*2))
				{
					a[ca[0]*2-1][j]=1;
					if(j==ca[2]*2+1)
					{
						break;
					}
				}
			}
			else
			{
				for(j=ca[0]*2-1;j<=ca[1]*2-1;j++)
				{
					a[j][ca[2]*2+1]=1;
				}
			}
		}
		q.push({0,0});
		a[0][0]=1;
		for(;!q.empty();)
		{
			y=q.front().fr;
			x=q.front().sc;
			q.pop();
			for(im=0;im<4;im++)
			{
				yy=y+vy[im];
				xx=(x+vx[im]+ma2*2)%(ma2*2);
				if(yy>=0&&yy<=ma*2&&!a[yy][xx])
				{
					q.push({yy,xx});
					a[yy][xx]=1;
				}
			}
		}
		if(a[ma*2][0])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}