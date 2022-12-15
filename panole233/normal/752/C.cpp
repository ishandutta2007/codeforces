#include<cstdio>
#include<cstring>

char s[2000001];
bool l,r,u,d;
int n,ans;

int main()
{
	scanf("%d",&n);
	scanf("%s",&s);
	l=r=u=d=0; ans=0;
	for (int i=0; i<n; i++)
	{
		if (s[i]=='U')
		{
			if (d) ans++,l=0,r=0,u=0,d=0;
			u=1;
		}else
		if (s[i]=='D')
		{
			if (u) ans++,l=0,r=0,u=0,d=0;
			d=1;
		}else
		if (s[i]=='L')
		{
			if (r) ans++,l=0,r=0,u=0,d=0;
			l=1;
		}else
		{
			if (l) ans++,l=0,r=0,u=0,d=0;
			r=1;
		}
	}
	printf("%d",ans+1);
	return 0;
}