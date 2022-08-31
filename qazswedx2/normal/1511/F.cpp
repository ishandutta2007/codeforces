#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
struct mat
{
	int v[305][305],x,y;
	mat(){memset(v,0,sizeof(v));x=y=0;}
}a,b;
mat operator*(const mat a,const mat b)
{
	mat c;
	c.x=a.x,c.y=b.y;
	for(int i=1;i<=c.x;i++)
		for(int k=1;k<=a.y;k++)
			for(int j=1;j<=c.y;j++)
				c.v[i][j]=(c.v[i][j]+1ll*a.v[i][k]*b.v[k][j])%mod;
	return c;
}
mat mfpow(mat x,int y)
{
	mat ans=x;
	y--;
	while(y)
	{
		if(y&1) ans=ans*x;
		x=x*x;
		y/=2;
	}
	return ans;
}
int n,m,ch[105][26],vis[105],ct=1;
void ins(char *s)
{
	int p=1;
	for(int i=0;s[i];i++)
	{
		int c=s[i]-'a';
		if(!ch[p][c]) ch[p][c]=++ct;
		p=ch[p][c];
	}
	vis[p]=1;
}
void add(int u,int v)
{
	a.v[v][u]++;
}
void dfs(int x,int y,int dep,int id)
{
	if(dep&&(x==1||y==1))
	{
	//	printf("dfs:x=%d,y=%d,dep=%d,id=%d\n",x,y,dep,id);
		if(y==1) swap(x,y);
		add((id-1)*5+dep,(y-1)*5+1);
		return;
	}
	for(int i=0;i<26;i++)
		if(ch[x][i]&&ch[y][i])
		{
			int xx=ch[x][i],yy=ch[y][i];
			dfs(xx,yy,dep+1,id);
			if(vis[xx]) dfs(1,yy,dep+1,id);
			if(vis[yy]) dfs(xx,1,dep+1,id);
			if(vis[xx]&&vis[yy])
				dfs(1,1,dep+1,id);
		}
}
char s[15];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		ins(s);
	}
	for(int i=1;i<=ct;i++)
	{
	//	printf("i=%d\n",i);
		dfs(1,i,0,i);
	}
	for(int i=1;i<=ct;i++)
	{
		for(int j=1;j<5;j++)
			add((i-1)*5+j,(i-1)*5+j+1);
	}
	a.x=a.y=b.x=ct*5;
	b.y=1;
	b.v[1][1]=1;
	a=mfpow(a,m);
	b=a*b;
	printf("%d\n",b.v[1][1]);
	return 0;
}