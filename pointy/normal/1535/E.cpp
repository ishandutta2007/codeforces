#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mem(x) memset(x,0,sizeof(x))
//const ll inf=1000000000000000000; 

const int N=300005;
int q;
ll a[N],c[N];
int lg[N];
bool used[N];
int fath[N][21],depth[N];
void dfs(int u,int fa)
{
	depth[u]=depth[fa]+1;
	fath[u][0]=fa;
	for (int i=1;i<=lg[depth[u]];i++)
	{
		fath[u][i]=fath[fath[u][i-1]][i-1];
	}
}

inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
} 

int ask(int x)
{
	for (int i=lg[depth[x]];i>=0;i--)
    {
    	if (used[fath[x][i]]==0) 
    	{
    		x=fath[x][i];
    	}
    }
    return x;
}

int main()
{
	q=read(),a[0]=read(),c[0]=read();
	for (int i=1;i<=300000;i++) 
	{
		lg[i]=lg[i-1]+(1<<lg[i-1]==i);
	}
	for (int i=1;i<=300000;i++) 
	{
		lg[i]--;
	}
	for (int i=1;i<=q;i++)
	{
		int tp=read();
		if (tp==1)
		{
			int p=read();
			a[i]=read(),c[i]=read();
			dfs(i,p);
		}
		else
		{
			ll v=read(),w=read();
			ll ans=0;
			ll ww=w;
			while (1)
			{
				int r=ask(v);
				if (used[r]) break;
				if (w>=a[r])
				{
					used[r]=1;
					w-=a[r];
					ans+=a[r]*c[r];
					a[r]=0;
				}
				else
				{
					a[r]-=w;
					ans+=w*c[r];
					w=0;
					break;
				}
			}
			printf("%lld %lld\n",ww-w,ans);
			fflush(stdout);
		}
	}
	return 0;
}