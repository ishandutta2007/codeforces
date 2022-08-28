#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
using namespace std;
typedef long long ll;
int n,a[8005],b[8005],vis[8005],visp[8005],b1[8005],b2[8005];
bool g[8005][8005];
ll ans=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j+=4)
		{
			int ch=getchar(),v=0;
			while(isspace(ch)) ch=getchar();
			if(ch>='0'&&ch<='9') v=ch-'0';
			else v=ch-'A'+10;
			g[i][j]=(v>>3)&1;
			g[i][j+1]=(v>>2)&1;
			g[i][j+2]=(v>>1)&1;
			g[i][j+3]=v&1;
		}
	}
	for(int j=1;j<=n;j++)
		for(int i=1;i<=n;i++)
			b[j]+=g[i][j];
	while(1)
	{
		int id=0;
		for(int i=1;i<=n;i++)
			if(!vis[i]&&!b[i])
			{
				id=i;
				break;
			}
		if(!id) break;
		vis[id]=1;
		for(int i=1;i<=n;i++)
			if(!vis[i]&&g[id][i])
			{
				b[i]--;
				ans+=614*n+1;
			}
	}
	int mx=0,id=0,ct=0,ct2=0;
	for(int i=1;i<=n;i++)
		if(mx<b[i]) mx=b[i],id=i;
	for(int i=1;i<=n;i++)
		if(!vis[i]&&g[i][id])
			visp[i]=1;
	visp[id]=1;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			ct+=visp[i];
			ct2+=!visp[i];
		}
		for(int j=1;j<=n;j++)
			if(!vis[i]&&!vis[j]&&g[j][i])
			{
				if(visp[i]==visp[j]) b1[i]++;
				else b2[i]++;
			}
	}
	ans+=3*ct*ct2;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(!vis[i]&&!vis[j]&&visp[i]==visp[j])
			{
				if(b2[i]!=b2[j]) ans+=3;
				else ans+=4;
			}
	printf("%I64d",ans);
	return 0;
}