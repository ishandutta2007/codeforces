#include <bits/stdc++.h>

using namespace std;

long long n,yk[26],a[5069],vy[4]={-1,0,1,0},vx[4]={0,1,0,-1};

int main()
{
	long long t,rr,i,j,y,x,y2,x2;
	string s;
	
	yk[3]=0;
	yk[17]=1;
	yk[20]=2;
	yk[11]=3;
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			a[i]=yk[s[i-1]-'A'];
		}
		y=0;
		x=0;
		for(i=1;i<=n;i++)
		{
			y+=vy[a[i]];
			x+=vx[a[i]];
			y2=0;
			x2=0;
			for(j=1;j<=n;j++)
			{
				if(y2+vy[a[j]]!=y||x2+vx[a[j]]!=x)
				{
					y2+=vy[a[j]];
					x2+=vx[a[j]];
				}
			}
			if(!y2&&!x2)
			{
				printf("%lld %lld\n",x,y);
				break;
			}
		}
		if(y2||x2)
		{
			printf("0 0\n");
		}
	}
}