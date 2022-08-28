#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<cctype>
using namespace std;
char buf[10000005],bufo[10000005];
int len=9000000,p1=len,p2=0;
int gc()
{
	if(p1==len) fread(buf,1,len,stdin),p1=0;
	return buf[p1++];
}
int read()
{
	int x=0,ch=gc();
	while(!isdigit(ch)) ch=gc();
	while(isdigit(ch)) x=x*10+ch-'0',ch=gc();
	return x;
}
void reads(char *s)
{
	int ch=gc(),t=0;
	while(isspace(ch)) ch=gc();
	while(!isspace(ch)) s[t++]=ch,ch=gc();
}
void print(int x)
{
	if(x>=10) print(x/10);
	bufo[p2++]=x%10+'0';
}
void flush()
{
	fwrite(bufo,1,p2,stdout);
	p2=0;
}
const int mod[55]={1000000007,1000000009,1000000021,1000000033,1000000087,1000000093,1000000097,1000000103,1000000123,1000000181,
				   1000000207,1000000223,1000000241,1000000271,1000000289,1000000297,1000000321,1000000349,1000000363,1000000403,
				   1000000409,1000000411,1000000427,1000000433,1000000439,1000000447,1000000453,1000000459,1000000483,1000000513,
				   1000000531,1000000579,1000000607,1000000613,1000000637,1000000663,1000000711,1000000753,1000000787,1000000801,
				   1000000829,1000000861,1000000871,1000000891,1000000901,1000000919,1000000931,1000000933,1000000993,1000001011};
int m1,m2;
const int bs=123456;
inline int addmod(int x,int mod)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x,int mod)
{
	return x<0?x+mod:x;
}
int fpow(int x,int y,int mod)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
int pw1[1000005],pw2[1000005],pn=3e5;
struct pt
{
	int v1,v2,len;
	pt(int v1=0,int v2=0,int len=0):v1(v1),v2(v2),len(len){}
};
inline pt operator+(const pt &x,const pt &y)
{
	return pt(addmod(1ll*x.v1*pw1[y.len]%mod[m1]+y.v1,mod[m1]),
			  addmod(1ll*x.v2*pw2[y.len]%mod[m2]+y.v2,mod[m2]),
			  x.len+y.len);
}
bool operator==(const pt &x,const pt &y)
{
	return x.v1==y.v1&&x.v2==y.v2&&x.len==y.len;
}
bool operator!=(const pt &x,const pt &y)
{
	return !(x==y);
}
struct edge
{
	int v,nxt;
}e[1000005];
int n,m,h[300005],t,c[300005][20],d[300005],lg[300005];
int tp[300005],dfn[300005],udfn[300005],sz[300005],son[300005],cnt;
int up[300005];
pt f[300005][20],rf[300005][20];
char s[300005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,int dep)
{
	d[u]=dep;
	c[u][0]=fa;
	sz[u]=1;
	son[u]=0;
	for(int i=1;i<=18;i++)
	{
		c[u][i]=c[c[u][i-1]][i-1];
		f[u][i]=f[u][i-1]+f[c[u][i-1]][i-1];
		rf[u][i]=rf[c[u][i-1]][i-1]+rf[u][i-1];
	}
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,dep+1);
		sz[u]+=sz[v];
		if(sz[son[u]]<sz[v]) son[u]=v;
	}
}
void dfs2(int u,int ttp)
{
	tp[u]=ttp;
	dfn[u]=++cnt;
	udfn[cnt]=u;
	if(son[u]) dfs2(son[u],ttp);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==c[u][0]||v==son[u]) continue;
		dfs2(v,v);
	}
}
/*int getans(int u,int k)
{
	while(k)
	{
		u=c[u][lg[k&-k]];
		k-=k&-k;
	}
	return u;
}*/
int getans(int u,int k)
{
	while(k>=d[u]-d[up[u]]+1)
	{
		k-=d[u]-d[up[u]]+1;
		u=c[up[u]][0];
	}
	while(k>=d[u]-d[tp[u]]+1)
	{
		k-=d[u]-d[tp[u]]+1;
		u=c[tp[u]][0];
	}
	return udfn[dfn[u]-k];
}
pt getansf(int u,int k)
{
	pt ans;
	while(k)
	{
		int q=lg[k&-k];
		ans=ans+f[u][q];
		u=c[u][q];
		k-=k&-k;
	}
	return ans;
}
pt getansrf(int u,int k)
{
	pt ans;
	while(k)
	{
		int q=lg[k&-k];
		ans=rf[u][q]+ans;
		u=c[u][q];
		k-=k&-k;
	}
	return ans;
}
int lca(int u,int v)
{
	if(d[u]<d[v]) swap(u,v);
	for(int i=18;i>=0;i--)
		if(d[c[u][i]]>=d[v])
			u=c[u][i];
	if(u==v) return u;
	for(int i=18;i>=0;i--)
		if(c[u][i]!=c[v][i])
			u=c[u][i],v=c[v][i];
	return c[u][0];
}
int main()
{
//	freopen("CF504E.in","r",stdin);
//	freopen("CF504E.out","w",stdout);
	srand(time(0));
	m1=rand()%50,m2=rand()%50;
	lg[1]=0;
	for(int i=2;i<=300000;i++)
		lg[i]=lg[i/2]+1;
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=pn;i++)
	{
		pw1[i]=1ll*pw1[i-1]*bs%mod[m1];
		pw2[i]=1ll*pw2[i-1]*bs%mod[m2];
	}
	n=read();
	reads(s+1);
	for(int i=1;i<=n;i++)
		f[i][0]=rf[i][0]=pt(s[i],s[i],1);
	for(int i=1;i<n;i++)
	{
		int u,v;
		u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1,0,1);
	dfs2(1,1);
	for(int i=1;i<=n;i++)
	{
		up[i]=tp[c[tp[c[tp[c[tp[i]][0]]][0]]][0]];
		if(!up[i]) up[i]=1;
	}
	m=read();
	for(int i=1;i<=m;i++)
	{
		int w,x,y,z,l,l2;
		w=read(),x=read(),y=read(),z=read();
		l=lca(w,x);
		l2=lca(y,z);
		if(d[w]-d[l]>d[y]-d[l2]) swap(w,y),swap(x,z),swap(l,l2);
		int len=d[w]-d[l],len2=d[y]-d[l2];
	//	printf("w=%d,x=%d,y=%d,z=%d\n",w,x,y,z);
		if(getansf(w,len)!=getansf(y,len))
		{
		//	printf("case 1:");
			int ans=0;
			for(int i=lg[len];i>=0;i--)
				if(d[c[w][i]]>=d[l]&&f[w][i]==f[y][i])
				{
					w=c[w][i];
					y=c[y][i];
					ans+=(1<<i);
				}
			print(ans);
			bufo[p2++]='\n';
		}
		else if(d[x]+d[w]-2*d[l]+1<=len2||
		getansf(w,len)+getansrf(getans(x,d[x]-d[l]-(len2-len)+1),len2-len)!=getansf(y,len2))
		{
		//	printf("case 2:%d,%d,%d,getans=%d\n",d[x]+d[w]-2*d[l]+1,len2,d[x]-d[l]-(len2-len)+1,getans(x,d[x]-d[l]-(len2-len)+1));
			int ans=len,nw=d[x]-d[l]+1;
			y=getans(y,len);
			for(int i=lg[len2-len];i>=0;i--)
			{
		//		printf("i=%d,len=%d,len2=%d,qwq=%d,getans=%d\n",i,len,len2,nw-(1<<i),getans(x,nw-(1<<i)));
				if(d[c[y][i]]>=d[l2]&&nw>=(1<<i)&&f[y][i]==rf[getans(x,nw-(1<<i))][i])
				{
					nw-=(1<<i);
					ans+=(1<<i);
					y=c[y][i];
				}
			}
			print(ans);
			bufo[p2++]='\n';
		}
		else
		{
		//	printf("case 3:");
			int ans=len2,nw1=d[w]+d[x]-2*d[l]+1-len2,nw2=d[z]-d[l2]+1;
			for(int i=lg[min(nw1,nw2)];i>=0;i--)
				if(nw1>=(1<<i)&&nw2>=(1<<i)&&rf[getans(x,nw1-(1<<i))][i]==rf[getans(z,nw2-(1<<i))][i])
				{
					nw1-=(1<<i);
					nw2-=(1<<i);
					ans+=(1<<i);
				}
			print(ans);
			bufo[p2++]='\n';
		}
		if(p2>=len) flush();
	}
	flush();
	return 0;
}