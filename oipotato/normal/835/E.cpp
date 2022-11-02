#include <cstdio>
using namespace std;
int a1[1010],a2[1010],a[1010],x,y,n,n1,n2,tot,s,pos,diff;
int work(int a[],int n)
{
	int l=1,r=n+1;
	for(;l<r-1;)
	{
		int mid=(l+r)>>1;
		printf("? %d",mid-l);
		for(int i=l;i<mid;i++)
			printf(" %d",a[i]);
		puts("");
		fflush(stdout);
		scanf("%d",&s);
		if(s==y||s==(x^y))
			r=mid;
		else l=mid;
	}
	return a[l];
}
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	pos=0;
	diff=0;
	for(int i=0;i<=9;i++)
	{
		printf("? ");
		tot=0;
		for(int j=1;j<=n;j++)
			if((j&(1<<i))==0)
				a[++tot]=j;
		printf("%d",tot);
		for(int j=1;j<=tot;j++)
			printf(" %d",a[j]);
		puts("");
		fflush(stdout);
		scanf("%d",&s);
		if(s==y||s==(x^y))
		{
			pos=i;
			diff+=1<<i;
		}
	}
	n1=n2=0;
	for(int i=1;i<=n;i++)
		if((i&(1<<pos))==0)
			a1[++n1]=i;
	int ans1=work(a1,n1);
	int ans2=ans1^diff;
	if(ans1>ans2)
	{
		int t=ans1;
		ans1=ans2;
		ans2=t;
	}
	printf("! %d %d\n",ans1,ans2);
	fflush(stdout);
	return 0;
}