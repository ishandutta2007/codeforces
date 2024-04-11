#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=55;
const int Max=5+(int)1e18;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
inline int mul(int a,int b)
{
	if (a==0||b==0) return 0;
	if (Max/a+1<b) return Max;
	return a*b;
}
inline int add(int a,int b){return min(a+b,Max);}
inline void Add(int &a,int b){a=add(a,b);}
inline void Mul(int &a,int b){a=mul(a,b);}
int fact[N],dp[N];
bool vis[N];
inline int fac(int n){return n<0?1:fact[n];}
int fa[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	for (int i=fact[0]=1;i<N;i++) fact[i]=mul(fact[i-1],i);
	for (int i=dp[0]=1;i<N;i++)
	for (int j=0;j<i;j++)
	dp[i]=add(dp[i],mul(dp[j],fac(i-j-2)));
	int T=read();
	while (T--)
	{
		int n=read(),k=read();
		for (int i=1;i<=n;i++) fa[i]=i;
		if (dp[n]<k) puts("-1");
		else
		{
			for (int x=0;x<n;)
			for (int j=1;x+j<=n;j++)
			if (mul(dp[n-x-j],fac(j-2))<k) k-=mul(dp[n-x-j],fac(j-2));
			else
			{
				print(x+j,' ');
				vis[j]=1;
				fa[1]=j;
				for (int i=2;i<=j;i++)
				{
					for (int t=1;t<=j;t++)
					if (i==j||find(i)!=find(t))
					if (!vis[t])
					{
						int tmp=mul(fac(j-i-1),dp[n-x-j]);
						if (tmp<k) k-=tmp;
						else
						{
							print(x+t,' ');
							fa[find(i)]=find(t);
							vis[t]=1;
							break;
						}
					}
				}
				x+=j;
				for (int i=1;i<=j;i++) vis[i]=0;
				for (int i=1;i<=j;i++) fa[i]=i;
				break;
			}
			puts("");
		}
	}
	
	return 0;
}