#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
char buf[1<<20],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p1=buf,p2=buf+fread(buf,1,1<<20,stdin)),*p1++)
int read()
{
	int f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
int abs(int x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 1000011;
void get_pre(ll* sum,int* pre,int n)
{
	static pll b[MAXN];
	for(int i=0;i<=n;++i)b[i]=pll(sum[i],i);
	std::sort(b,b+n+1);
	for(int i=0;i<=n;++i)
		if(i>0&&b[i].first==b[i-1].first)pre[b[i].second]=b[i-1].second;
		else pre[b[i].second]=-1;
	for(int i=1;i<=n;++i)umax(pre[i],pre[i-1]);//,printf("%d ",pre[i]);
}
int n;
int a[2][MAXN],fir[MAXN],sec[MAXN],pre[MAXN];
ll sum[MAXN];

int res[MAXN];
std::map<pii,int>f;
int mdfs(int x,int y)
{
	if(max(fir[x],sec[y])<0)return 0;
	if(f.count(pii(x,y)))return f[pii(x,y)];
	if(fir[x]==-1)
		return f[pii(x,y)]=res[sec[y]]+1;
	if(sec[y]==-1)
		return f[pii(x,y)]=res[fir[x]]+1;
	//printf("Compute (%d,%d)\n",x,y);
	if(fir[x]>=sec[y])
	{
		return f[pii(x,y)]=max(mdfs(fir[x],y)+1,res[min(fir[x],y)]+1);
	}
	else return f[pii(x,y)]=max(mdfs(x,sec[y])+1,res[min(x,sec[y])]+1);
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)a[0][i]=read();
	for(int i=1;i<=n;++i)a[1][i]=read();
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[0][i];
	get_pre(sum,fir,n);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[1][i];
	get_pre(sum,sec,n);
	for(int i=1;i<=n;++i)sum[i]=sum[i-1]+a[0][i]+a[1][i];
	get_pre(sum,pre,n);
	f[pii(0,0)]=0,res[0]=0;
	for(int i=1;i<=n;++i)
	{
		res[i]=res[i-1];
		if(pre[i]>=0)umax(res[i],res[pre[i]]+1);
		//printf("i=%d: ",i);
		mdfs(i,i);
		umax(res[i],f[pii(i,i)]);
		umax(f[pii(i,i)],res[i]);
		//[<F9>]printf("res[%d]=%d\n",i,res[i]);
	}
	//puts("");
	printf("%d\n",res[n]);
	return 0;
}