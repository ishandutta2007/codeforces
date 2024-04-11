#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long x,y,i,ln,x1=0,y1=0,m,n;
	string s;
	
	scanf("%lld%lld",&x,&y);
	cin>>s;
	ln=s.length();
	long long a[2][ln];
	for(i=0;i<ln;i++)
	{
		a[0][i]=x1;
		a[1][i]=y1;
		if(s[i]=='U')
		{
			y1++;
		}
		else if(s[i]=='D')
		{
			y1--;
		}
		else if(s[i]=='L')
		{
			x1--;
		}
		else if(s[i]=='R')
		{
			x1++;
		}
	}
	for(i=0;i<ln;i++)
	{
		if(x1==0)
		{
			if(a[0][i]!=x)
			{
				continue;
			}
			m=0;
		}
		else
		{
			if((x-a[0][i])%x1!=0)
			{
				continue;
			}
			m=(x-a[0][i])/x1;
		}
		if(y1==0)
		{
			if(a[1][i]!=y)
			{
				continue;
			}
			n=0;
		}
		else
		{
			if((y-a[1][i])%y1!=0)
			{
				continue;
			}
			n=(y-a[1][i])/y1;
		}
		if((x1==0||y1==0||m==n)&&m>=0&&n>=0)
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
}