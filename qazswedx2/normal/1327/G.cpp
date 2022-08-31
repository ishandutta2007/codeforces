#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,ch[100005][26],cnt=1,fail[100005],c[100005],q[1000005],head,tail;
int a[15],at,cnt2[100005],val=14;
ll g[15][1005][2],f[20005][1005];
char s[1000005];
void ins(char *s,int val)
{
	int p=1;
	for(int i=0;s[i];i++)
	{
		int &nw=ch[p][s[i]-'a'];
		if(!nw) nw=++cnt;
		p=nw; 
	}
	c[p]+=val;
}
void getfail()
{
	for(int i=0;i<14;i++)
		ch[0][i]=1;
	fail[1]=0;
	head=0,tail=1;
	q[1]=1;
	while(head<tail)
	{
		head++;
		int u=q[head];
		for(int i=0;i<14;i++)
			if(!ch[u][i]) ch[u][i]=ch[fail[u]][i];
			else fail[ch[u][i]]=ch[fail[u]][i],q[++tail]=ch[u][i];
	}
	for(int i=1;i<=tail;i++)
		c[q[i]]+=c[fail[q[i]]];
}
int main()
{
	memset(f,0xcf,sizeof(f));
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%s%d",s,&x);
		ins(s,x);
	}
	scanf("%s",s+1);
	n=strlen(s+1);
	getfail();
	for(int i=1;i<=n;i++)
		if(s[i]=='?') a[++at]=i;
	a[at+1]=n+1; 
	for(int i=0;i<=at;i++)
		for(int j=1;j<=cnt;j++)
		{
			int nw=j;
			ll ans=0;
			for(int k=a[i]+1;k<a[i+1];k++)
				nw=ch[nw][s[k]-'a'],ans+=c[nw];
			g[i][j][0]=nw;
			g[i][j][1]=ans;
		}
	f[0][g[0][1][0]]=g[0][1][1];
	for(int i=0;i<(1<<val);i++)
	{
		cnt2[i]=cnt2[i/2]+i%2;
		int v=cnt2[i];
		if(v>=at) continue;
		for(int j=1;j<=cnt;j++)
			for(int k=1;k<=val;k++)
				if(!(i&(1<<(k-1))))
				{
					int nw=i+(1<<(k-1)),nxt=ch[j][k-1];
					f[nw][g[v+1][nxt][0]]=max(f[nw][g[v+1][nxt][0]],f[i][j]+g[v+1][nxt][1]+c[nxt]);
				}
	}
	ll ans=-1e18;
	for(int i=0;i<(1<<val);i++)
		if(cnt2[i]==at)
			for(int j=1;j<=cnt;j++)
				ans=max(ans,f[i][j]);
	printf("%I64d",ans);
	return 0;
}