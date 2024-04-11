#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[500005],b[500005];
char s[500005];
inline int getpre(int x)
{
	return x>1?x-1:n;
}
inline int getnxt(int x)
{
	return x<n?x+1:1;
}
int main()
{
	scanf("%d%d%s",&n,&m,s+1);
	int fl=0;
	for(int i=1;i<=n;i++)
		if(s[getpre(i)]==s[i]||s[getnxt(i)]==s[i])
		{
			a[i]=1;
			fl=i;
		}
	if(!fl)
	{
		if(m%2==0)
		{
			for(int i=1;i<=n;i++)
				printf("%c",s[i]);
		}
		else
		{
			for(int i=1;i<=n;i++)
				if(s[i]=='W') printf("B");
				else printf("W");
		}
		return 0;
	}
	for(int l=getnxt(fl);l!=fl;l=getnxt(l))
	{
		if(a[l]) continue;
		int r=l,len=1;
		while(!a[getnxt(r)]) r=getnxt(r),len++;
		//printf("l=%d,r=%d,len=%d\n",l,r,len);
		for(int i=l,j=1;j<=min(m,(len+1)/2);i=getnxt(i),j++)
		{
			a[i]=1;
			s[i]=s[getpre(l)];
		}
		for(int i=r,j=1;j<=min(m,(len+1)/2);i=getpre(i),j++)
		{
			a[i]=1;
			s[i]=s[getnxt(r)];
		}
		l=r;
	}
	if(m%2==0)
	{
		for(int i=1;i<=n;i++)
			printf("%c",s[i]);
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]) printf("%c",s[i]);
			else if(s[i]=='W') printf("B");
			else printf("W");
		}
	}
	return 0;
}