#include<bits/stdc++.h>
#define sz 200020
#define mod 998244353ll
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
struct hh{int x,y;}a[sz];
inline int id(hh x){return max(x.x,x.y);}
inline bool cmp(const hh &x,const hh &y){return id(x)<id(y);}
ll dp[sz][2];
hh p[sz][2];
inline bool cmpx(const hh &x,const hh &y){return x.x==y.x?x.y>y.y:x.x<y.x;}//left
inline bool cmpy(const hh &x,const hh &y){return x.y==y.y?x.x>y.x:x.y<y.y;}//right
inline ll dis(const hh &x,const hh &y){return abs(x.x-y.x)+abs(x.y-y.y);}
int main()
{
	file();
	int i,j,k,x,y,z;
	read>>n;
	for (i=1;i<=n;i++) read>>a[i].x>>a[i].y;
	sort(a+1,a+n+1,cmp);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=dp[0][1]=0;
	for (i=j=z=1;i<=n;i=j+1,++z,++j)
	{
		while (id(a[j+1])==id(a[j])) ++j;
		p[z][0]=p[z][1]=a[i];
		for (k=i+1;k<=j;k++)
		{
			if (cmpx(a[k],p[z][0])) p[z][0]=a[k];
			if (cmpy(a[k],p[z][1])) p[z][1]=a[k];
		}
		for (x=0;x<2;x++)
			for (y=0;y<2;y++)
				dp[z][x]=min(dp[z][x],dp[z-1][y]+dis(p[z-1][y],p[z][!x])+dis(p[z][!x],p[z][x]));
	}
	cout<<min(dp[z-1][0],dp[z-1][1]);
}