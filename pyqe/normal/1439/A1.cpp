#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,zs=0;
bitset<169> a[169];
bitset<4> ex;
pair<long long,long long> sq[10069][3];

void op(long long y,long long x,long long w)
{
	long long i,yy,xx,p=0;
	
	zs++;
	for(i=0;i<4;i++)
	{
		if(i!=w)
		{
			yy=y+i/2;
			xx=x+i%2;
			a[yy][xx]=!a[yy][xx];
			sq[zs][p]={yy,xx};
			p++;
		}
	}
}

int main()
{
	long long t,rr,i,j,r,c;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			cin>>s;
			for(j=1;j<=m;j++)
			{
				a[i][j]=s[j-1]-'0';
			}
		}
		zs=0;
		for(i=n;i;i--)
		{
			for(j=m;j;j--)
			{
				if((i>n/2*2||j>m/2*2)&&a[i][j])
				{
					op(i-1+(i==1),j-1+(j==1),3*(i==1||j==1));
				}
			}
		}
		for(i=1;i<=n/2*2;i+=2)
		{
			for(j=1;j<=m/2*2;j+=2)
			{
				c=0;
				for(r=0;r<4;r++)
				{
					ex[r]=a[i+r/2][j+r%2];
					c+=ex[r];
				}
				for(r=0;r<4;r++)
				{
					if(ex[r]^(c%2))
					{
						op(i,j,r);
					}
				}
			}
		}
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			for(j=0;j<3;j++)
			{
				printf("%lld %lld%c",sq[i][j].fr,sq[i][j].sc," \n"[j==2]);
			}
		}
	}
}