#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,x,tans[10005],ct;
int main()
{
	printf("a\n");
	fflush(stdout);
	scanf("%d",&n);
	if(!n) return 0;
	/*printf("b\n");
	fflush(stdout);
	scanf("%d",&x);
	if(n!=x)
	{
		if(n>x)
		{
			for(int i=1;i<=n;i++)
				printf("b");
			printf("\n");
			fflush(stdout);
		}
		else
		{
			for(int i=1;i<=x;i++)
				printf("a");
			printf("\n");
			fflush(stdout);
		}
		return 0;
	}*/
	if(n==300)
	{
		for(int i=1;i<=n;i++)
			printf("b");
		printf("\n");
		fflush(stdout);
		return 0;
	} 
	n++;
	if(n==2)
	{
		printf("b\n");
		fflush(stdout);
		scanf("%d",&x);
		if(!x) return 0;
		if(x==2)
		{
			printf("aa\n");
			return 0;
		}
		printf("ab\n");
		fflush(stdout);
		scanf("%d",&x);
		if(!x) return 0;
		printf("ba\n");
		fflush(stdout);
		scanf("%d",&x);
		if(!x) return 0;
	}
	for(int i=n;i>0;i--)
	{
		for(int j=1;j<=n;j++)
		{
			if(i<j) printf("a");
			else printf("b");
		}
		printf("\n");
		fflush(stdout);
		scanf("%d",&tans[i]);
		if(!tans[i]) return 0;
		if(i==n-1&&tans[n-1]==tans[n])
		{
			for(int i=1;i<n;i++)
				printf("b");
			printf("\n");
			fflush(stdout);
			return 0;
		}
	}
	ct=n-tans[n];
	for(int i=2;i<=n;i++)
		if(tans[i]<tans[i-1]) ct--;
	if(ct) printf("b");
	else printf("a");
	for(int i=2;i<=n;i++)
		if(tans[i]<tans[i-1]) printf("b");
		else printf("a");
	printf("\n");
	fflush(stdout);
	return 0;
	/*int mn=1e9,mx=0;
	for(int i=1;i<n;i++)
	{
		mn=min(mn,tans[i]);
		mx=max(mx,tans[i]);
	}
	if(tans[1]==mx) ct=tans[1]-1;
	else ct=tans[1]+1;
	for(int i=1;i<n;i++)
	{
		if(tans[i]==mn) printf("b"),ct--;
		else printf("a");
	}
	if(ct) printf("b");
	else printf("a");
	printf("\n");
	fflush(stdout);*/
	return 0;
}