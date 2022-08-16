#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define O4 __inline__ __attribute__((always_inline))
#ifdef ONLINE_JUDGE
#define getchar nc
#endif
const int lim=4005;
struct node{int x,l,r;}w[lim];
int s[lim][lim],n,k,f[lim],g[lim],heat,tail;
int F(int x,int y,int z){return (s[x][x]+s[y][y]-2*s[x][y])/2+f[y]+z;}
namespace FastIO{
	O4 char nc(){
		static char buf[100000],*p1=buf,*p2=buf;
		return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
	}
	O4 int read(){
		char t;int u=0,k=1;t=getchar();
		while(t<'0'||t>'9'){if(t=='-')k=-1;t=getchar();}
		while(t>='0'&&t<='9'){u=u*10+t-'0';t=getchar();}
		return u*k;
	}
}
using namespace FastIO;
void work(int x)
{
	heat=1,tail=1;int i;
	f[0]=g[0]=0;w[tail]=(node){0,1,n};
	for(i=1;i<=n;i++)
	{
		while(heat<tail&&w[heat].r<i)heat++;
		f[i]=F(i,w[heat].x,x),g[i]=g[w[heat].x]+1;
		if(F(n,i,x)>=F(n,w[tail].x,x))continue;
		while(heat<tail&&F(w[tail].l,w[tail].x,x)>F(w[tail].l,i,x))tail--;
		int l=w[tail].l,r=w[tail].r+1;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(F(mid,i,x)<F(mid,w[tail].x,x))r=mid;
			else l=mid+1;
		}
		w[tail].r=r-1;
		w[++tail]=(node){i,r,n};
	}
}
int main()
{
	int i,j,x;
	n=read();k=read();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			x=read();
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+x;
		}
	}
	int l=0,r=s[n][n],ans;
	while(l<r)
	{
		int mid=(l+r)>>1;
		work(mid);
		if(g[n]>k){l=mid+1;}
		else r=mid;
	}
	work(r);printf("%d",f[n]-r*k);
}