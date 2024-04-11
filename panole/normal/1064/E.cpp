#include<cstdio>
#include<cstring>

char s[10];
bool bo0,bo1,la;
int ans[31],ansa,ansb;

int main()
{
	int n,l,r;
	scanf("%d",&n);
	printf("0 500000\n"); fflush(stdout);la=1; ans[1]=0;
	if (n==1) {printf("0 0 1 0\n"); fflush(stdout);return 0;}
	for (int i=1; i<n; i++)
	{
		scanf("%s",s);
		if (s[0]=='b') bo1=1; else bo1=0;
		if (i==1) l=0,r=(1e9); else 
		if (bo0==bo1) 
		{
			if (la) l=(l+r)/2; else r=(l+r)/2;
		}
		else 
		{
			if (la) r=(l+r)/2; else l=(l+r)/2;
			la=(la^1);
		}
		bo0=bo1; printf("%d 500000\n",(l+r)/2); fflush(stdout);
		ans[i+1]=(l+r)/2;
	}
	scanf("%s",s);
	if (s[0]=='b') bo1=1; else bo1=0;
	if (bo0^bo1^la)
	{
		int mi=(1e9)+1;
		for (int i=1; i<n; i++)
			if (ans[i]>ans[n]&&ans[i]<mi) mi=ans[i];
		if (mi==(1e9)+1) printf("0 0 1 0\n");
		else printf("%d 0 %d 1000000\n",ans[n],mi);
		fflush(stdout);
	} else
	{
		int ma=-1;
		for (int i=1; i<n; i++)
			if (ans[i]<ans[n]&&ans[i]>ma) ma=ans[i];
		printf("%d 0 %d 1000000\n",ans[n],ma);fflush(stdout);
	}
	return 0;
}