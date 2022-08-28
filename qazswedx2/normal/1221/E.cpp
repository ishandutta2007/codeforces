#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,A,B,a[1000005],at,n;
char s[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		at=0;
		scanf("%d%d%s",&A,&B,s+1);
		n=strlen(s+1);
		int las=1;
		for(int i=1;i<=n;i++)
			if(s[i]=='X')
			{
				a[++at]=i-las;
				las=i+1;
			}
		a[++at]=n+1-las;
		int ct1=0,ct2=0,ct3=0,len;
		for(int i=1;i<=at;i++)
		{
			if(a[i]<B) continue;
			if(a[i]<A) ct1++;
			else if(a[i]<2*B) ct2++;
			else ct3++,len=a[i];
		}
		if(ct1||ct3>=2)
		{
			printf("No\n");
			continue;
		}
		if(ct3==0)
		{
			if(ct2%2) printf("Yes\n");
			else printf("No\n");
			continue;
		}
		int fl=0;
		for(int i=1;i<=len;i++)
		{
			int x=i-1,y=len-i-A+1,nw=ct2;
			if(y<0) break;
			if(x>=B)
			{
				if(x<A||x>=2*B) continue;
				if(x<2*B) nw++;
			}
			if(y>=B)
			{
				if(y<A||y>=2*B) continue;
				if(y<2*B) nw++;
			}
			if(nw%2==0) fl=1;
		}
		if(fl) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}