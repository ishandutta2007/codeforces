#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 1011,mod = 998244353;
int a[MAXN][MAXN],pw[MAXN];
int loc[MAXN],res[MAXN];
bool vr[MAXN],vc[MAXN];
int n;
void Del(int r)
{
	for(int i=1;i<=2*n;++i)
	{
		if(vr[i])continue;
		for(int j=1;j<=n;++j)
			if(a[r][j]==a[i][j])vr[i]=1;
	}
}
int main()
{
	pw[0]=1;
	for(int i=1;i<MAXN;++i)pw[i]=pw[i-1]*2%mod;
	int task=read();
	while(task--)
	{
		n=read();
		int ans=1;
		for(int i=1;i<=2*n;++i)vr[i]=0;
		for(int i=1;i<=2*n;++i)
			for(int j=1;j<=n;++j)a[i][j]=read();
		for(int x=1;x<=n;++x)
		{
			for(int c=1;c<=n;++c)
			{
				for(int i=1;i<=n;++i)loc[i]=0;
				for(int r=1;r<=2*n;++r)
					if(!vr[r])
					{
						if(loc[a[r][c]])loc[a[r][c]]=-1;
						else loc[a[r][c]]=r;
					}
				for(int i=1;i<=n;++i)
					if(loc[i]>0)
					{
						vr[loc[i]]=1;
						Del(loc[i]);
						res[x]=loc[i];
						goto Nxt;
					}
			}
			ans=ans*2%mod;
			for(int c=1;c<=n;++c)
				if(!vc[c]){vc[c]=1;break;}
			for(int r=1;r<=2*n;++r)
				if(!vr[r]){vr[r]=1,res[x]=r,Del(r);break;}
Nxt:;
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;++i)printf("%d ",res[i]);
		puts("");
	}
	return 0;
}