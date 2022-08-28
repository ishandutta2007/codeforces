#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,b[1000005],ans,ch[10000005][2],ct=1,f[10000005];
void ins(int x)
{
	int u=1;
	for(int i=30;i>=0;i--)
	{
		int v=(x>>i)&1;
		if(!ch[u][v]) ch[u][v]=++ct;
		u=ch[u][v];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		ins(b[i]);
	}
	for(int i=1;i<=ct;i++)
	{
		f[i]+=(ch[i][0]&&ch[i][1]);
		f[ch[i][0]]=f[ch[i][1]]=f[i];
		ans=max(ans,f[i]);
	}
	printf("%d\n",n-ans-1);
	return 0;
}