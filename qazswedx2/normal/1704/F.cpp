#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,f[1000005],pn=1e6;
int vis[1000005];
char s[1000005];
int main()
{
	f[1]=0;
	for(int i=2;i<=100;i++)
	{
		for(int j=1;j<i;j++)
			vis[f[j-1]^f[i-j-1]]++;
		int nw=0;
		while(vis[nw]) nw++;
		f[i]=nw;
		for(int j=1;j<i;j++)
			vis[f[j-1]^f[i-j-1]]--;
	//	printf("%d ",f[i]);
	}
	for(int i=101;i<=pn;i++)
		f[i]=f[i-34];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%s",&n,s+1);
		int ct0=0,ct1=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='R') ct0++;
			else ct1++;
		if(ct0>ct1)
		{
			printf("Alice\n");
			continue;
		}
		if(ct1>ct0)
		{
			printf("Bob\n");
			continue;
		}
		int ans=0;
		for(int l=1,r;l<=n;l=r+1)
		{
			r=l;
			while(r<n&&s[r+1]!=s[r]) r++;
			ans^=f[r-l+1];
		}
		if(ans) printf("Alice\n");
		else printf("Bob\n");
	}
}