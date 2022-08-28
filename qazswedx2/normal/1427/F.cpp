#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,vis[100005],st[100005][3],tp,f[100005],pt,a[100005],deg[100005];
int b[100005][3],visp[100005],visrt[100005],crt;
inline void print(int x)
{
	printf("%d %d %d\n",b[x][0],b[x][1],b[x][2]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=3*n;i++)
	{
		int x;
		scanf("%d",&x);
		vis[x]=1;
	}
	for(int i=1;i<=6*n;i++)
	{
		if(!tp||st[tp][0]!=vis[i])
		{
			st[++tp][0]=vis[i];
			st[tp][1]=1;
			st[tp][2]=++pt;
			a[pt]=vis[i];
			f[pt]=st[tp-1][2];
			b[pt][0]=i;
		}
		else
		{
			b[st[tp][2]][st[tp][1]]=i;
			st[tp][1]++;
			if(st[tp][1]==3) tp--;
		}
	}
	for(int i=1;i<=2*n;i++)
		deg[f[i]]++;
	//for(int i=1;i<=2*n;i++)
	//	printf("i=%d,a=%d,b=%d,%d,%d,f=%d,deg=%d\n",i,a[i],b[i][0],b[i][1],b[i][2],f[i],deg[i]);
	for(int i=1;i<=2*n;i++)
		if(a[i]==0&&!f[i])
		{
			visrt[i]=1;
			crt++;
		}
	for(int i=1;i<=2*n;i++)
	{
		if(i%2)
		{
			for(int j=1;j<=2*n;j++)
				if(a[j]==1&&!visp[j]&&!deg[j])
				{
					print(j);
					visp[j]=1;
					deg[f[j]]--;
					break;
				}
		}
		else
		{
			for(int j=1;j<=2*n;j++)
				if(a[j]==0&&!visp[j]&&!deg[j]&&(crt>1||!visrt[j]||i==2*n))
				{
					print(j);
					visp[j]=1;
					deg[f[j]]--;
					if(visrt[j]) crt--;
					break;
				}
		}
	}
	return 0;
}