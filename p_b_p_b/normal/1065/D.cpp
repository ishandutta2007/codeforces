#include<bits/stdc++.h>
#define sz 15
#define mod (int)(1e9+7)
using namespace std;
typedef long long ll;
struct FastIO
{
    inline FastIO& operator>>(int& x)
	{
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(ll& x)
	{
        x=0;char f=0,ch=getchar();
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        return x=(f?-x:x),*this;
    }
    inline FastIO& operator>>(double& x)
	{
        x=0;char f=0,ch=getchar();
        double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
        if(ch=='.')
        {
        	ch=getchar();
			while(ch<='9'&&ch>='0') x+=d*(ch^48),d*=0.1,ch=getchar();
        }
        return x=(f?-x:x),*this;
    }
}read;
void file()
{
	#ifndef ONLINE_JUDGE
	freopen("a.txt","r",stdin);
	#endif
}
unsigned int log2(int x){unsigned int ret;__asm__ __volatile__ ("bsrl %1, %%eax":"=a"(ret):"m"(x));return ret;}
inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int n;
struct hh
{
	int t,rep;
	hh(int x=0,int y=0){t=x,rep=y;}
	const bool operator < (const hh &y){return t==y.t?rep<y.rep:t<y.t;}
	const hh operator + (const hh &y){return hh(t+y.t,rep+y.rep);}
};
hh min(hh x,hh y){return x<y?x:y;}
int id(int x,int y,int t){return n*(x-1)+y+n*n*t;}
// 0:horse 1:car 2:qween
int a[sz][sz];
int X[sz*sz],Y[sz*sz];
hh dis[sz*sz<<3][sz*sz<<3];
int fx[8][2]={{-2,-1},{-1,-2},{2,-1},{-1,2},{-2,1},{1,-2},{1,2},{2,1}};
bool in(int x,int y){return x>0&&y>0&&x<=n&&y<=n;}
hh d[sz*sz][3];
int main()
{
	file();
	int i,j,k,x,y,z;
	read>>n;
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			read>>k,X[k]=i,Y[k]=j;
	memset(dis,0x3f,sizeof(dis));memset(d,0x3f,sizeof(d));
	for (i=1;i<=n;i++) for (j=1;j<=n;j++)
	{
		for (x=0;x<3;x++)
			for (y=0;y<3;y++)
				dis[id(i,j,x)][id(i,j,y)]=hh(1,1);
				
		for (k=0;k<8;k++)
		{
			x=i+fx[k][0],y=j+fx[k][1];
			if (!in(x,y)) continue;
			dis[id(i,j,0)][id(x,y,0)]=hh(1,0);
		}
		
		for (k=1;k<=n;k++) 
			dis[id(i,j,1)][id(i,k,1)]=dis[id(i,j,1)][id(k,j,1)]=hh(1,0);
		
		for (k=-n;k<=n;k++)
		{
			if (in(i+k,j+k)) dis[id(i,j,2)][id(i+k,j+k,2)]=hh(1,0);
			if (in(i+k,j-k)) dis[id(i,j,2)][id(i+k,j-k,2)]=hh(1,0);
			if (in(i-k,j+k)) dis[id(i,j,2)][id(i-k,j+k,2)]=hh(1,0);
			if (in(i-k,j-k)) dis[id(i,j,2)][id(i-k,j-k,2)]=hh(1,0);
		}
	}
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			for (k=0;k<3;k++)
				dis[id(i,j,k)][id(i,j,k)]=hh(0,0);
	for (k=1;k<=id(n,n,2);k++)
		for (i=1;i<=id(n,n,2);i++)
			for (j=1;j<=id(n,n,2);j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	hh ans=hh(2333333,23333333);
	for (i=0;i<3;i++) d[1][i]=hh(0,0);
	for (i=2;i<=n*n;i++)
		for (j=0;j<3;j++)
			for (k=0;k<3;k++)
				d[i][j]=min(d[i][j],d[i-1][k]+dis[id(X[i-1],Y[i-1],k)][id(X[i],Y[i],j)]);
	for (i=0;i<3;i++) ans=min(ans,d[n*n][i]);
	printf("%d %d",ans.t,ans.rep);
}