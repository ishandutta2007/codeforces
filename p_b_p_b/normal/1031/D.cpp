#include<bits/stdc++.h>
#define sz 6666
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
char a[sz][sz];
int n,K;
int f[sz][sz];
char ans[sz];
bool vis[sz][sz];
int main()
{
	file();/*something to add*/
	int i,j;
	/*something to add*/read>>n>>K;
	for (i=1;i<=n;i++) scanf("%s",&a[i][1]);
	for /*something to add*/(i=1;i<=n;i++)
	{
		/*something to add*/for (j=1;j<=n;j++)
		{
			/*something to add*/f[i][j]=max(f[i-1][j],f[i][j-1])+(a[i][j]=='a');
			if (i+j-1-f[i][j]<=K) a[i][j]='a';
		}
	}
	putchar(a[1][1]);
	vis[1][1]=1;/*something to add*/
	for(i=3;i<=n+n;i++)
	{/*something to add*/
		char now='z'+1;
		for (j=max(1,i-n);j<i&&j<=n;j++)
			if (vis[j-1][i-j]||vis[j][i-j-1]) 
				now=min(now,a[j][i-j]);	
		/*something to add*/putchar(now);/*something to add*/
		for (j=max(1,i-n);j<i&&j<=n;j++)
			/*something to add*/if (vis[j-1][i-j]||vis[j][i-j-1])
				if (a[j][i-j]==now) vis[j][i-j]=1;  
	}/*something to add*/
}