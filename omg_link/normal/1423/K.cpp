#include<cstdio>
#include<cctype>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<algorithm>
using namespace std;
const int N=1e6+600;

int gti(void)
{
	char c=getchar();
	int ret=0,st=1;
	for (;c!='-'&&!isdigit(c);c=getchar());
	if (c=='-') st=-1,c=getchar();
	for (;isdigit(c);c=getchar()) ret=ret*10+c-'0';
	return ret*st;
}

bool vis[N];
int pri[N],cnt,tag[N];
void getpri(int n)
{
	tag[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!vis[i])
		{
			pri[++cnt]=i,++tag[i];
			if (1ll*i*i<=n) --tag[i*i];
		}
		for (int j=1;j<=cnt&&1ll*i*pri[j]<=n;j++)
		{
			vis[i*pri[j]]=true;
			if (i%pri[j]==0) break;
		}
	}
	for (int i=2;i<=n;i++)
		tag[i]+=tag[i-1];
}

int main(void)
{
	getpri(1e6);
	for (int t=gti();t>=1;t--)
		printf("%d\n",tag[gti()]);
	return 0;
}