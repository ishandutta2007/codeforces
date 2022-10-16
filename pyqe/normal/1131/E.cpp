#include <bits/stdc++.h>

using namespace std;

long long n,inf=1e18;
string a[100069];
bitset<26> vtd[100069];

int main()
{
	long long i,j,ln,c,mx,ft,ls,sm=0,z=-inf;
	char ch;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		ln=a[i].length();
		for(j=0;j<26;j++)
		{
			vtd[i][j]=vtd[i-1][j];
		}
		for(j=0;j<ln;j++)
		{
			vtd[i][a[i][j]-'a']=1;
		}
	}
	for(i=n;i;i--)
	{
		ln=a[i].length();
		c=0;
		mx=-1;
		ft=-1;
		for(j=0;j<ln;j++)
		{
			c++;
			if(j==ln-1||a[i][j]!=a[i][j+1])
			{
				if(i==n||a[i][j]==ch)
				{
					mx=max(mx,c);
				}
				if(ft==-1)
				{
					ft=c;
				}
				ls=c;
				c=0;
			}
		}
		z=max(z,(mx+1)*(sm+1)-1);
		if(i-1)
		{
			if(i==n||a[i][0]==ch)
			{
				z=max(z,(ft+vtd[i-1][a[i][0]-'a']+1)*(sm+1)-1);
			}
			if(i==n||a[i][ln-1]==ch)
			{
				z=max(z,(ls+vtd[i-1][a[i][ln-1]-'a']+1)*(sm+1)-1);
			}
			if(a[i][0]==a[i][ln-1]&&vtd[i-1][a[i][0]-'a']&&(i==n||a[i][0]==ch))
			{
				z=max(z,(ft+ls+2)*(sm+1)-1);
			}
		}
		if(!(mx==ln&&(i==n||a[i][0]==ch)))
		{
			break;
		}
		sm=(ln+1)*(sm+1)-1;
		ch=a[i][0];
	}
	printf("%lld\n",z);
}