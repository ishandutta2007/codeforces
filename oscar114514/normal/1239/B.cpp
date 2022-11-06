#include<bits/stdc++.h>
using namespace std;
int n,m;
char t[333333];
int a[333333],s[333333];
int b[333333];
int main()
{
	scanf("%d %s",&n,t+1);
	for(int i=1;i<=n;i++)
	{
		a[i]=(t[i]=='('?1:-1);
		s[i]=a[i]+s[i-1];
	}
	int minn=0x3f3f3f3f,minp;
	for(int i=0;i<n;i++)
	{
		if(minn>s[i])minp=i+1,minn=s[i];
	}
//	cerr<<minp<<endl;
	for(int i=1;i<=n;i++)
	{
		b[i]=a[(i+minp-2+n)%n+1];
		s[i]=s[i-1]+b[i];
	}
//	for(int i=1;i<=n;i++)cerr<<b[i]<<' ';cerr<<endl;
	if(s[n]!=0)return printf("0\n1 1\n"),0;
	int orig=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]==0)orig++;
	}
	int maxx=orig,l=0,r=1;
//	cerr<<maxx<<endl;
	int cnt=0,last=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]==2)cnt++;
		else if(s[i]<2)
		{
			if(orig+cnt>maxx)
			{
				maxx=orig+cnt;
				l=last,r=i;
			}
			cnt=0;
			last=i;
		}
	}
	last=0;cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]==1)cnt++;
		else if(s[i]==0)
		{
			if(cnt+1>maxx)
			{
				maxx=cnt;
				l=last,r=i;
			}
			last=i;
			cnt=0;
		}
	}
//	cerr<<l<<' '<<r<<endl;
	printf("%d\n%d %d\n",maxx,(l+minp-1+n)%n+1,(r+minp-2+n)%n+1);
	return 0;
}