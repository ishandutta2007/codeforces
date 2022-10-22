#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int Mod=998244353;
const int M=2010;
int n,m,a[M][M],b[M],c[M],sz[M<<1],f[M<<1];
string s;
vector<int>v[M<<1];

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

void work1()
{
	int cnt=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j]==2)cnt++;
	cout<<poww(2,cnt);
}

void work2()
{
	int res=0;
	for (int w=0;w<2;w++)
	{
		int ans=1;
		for (int i=1;i<=n;i++)
		{
			int cnt=0,sum=0;
			for (int j=1;j<=m;j++)
				if (a[i][j]==2)sum++;
				else cnt+=a[i][j];
			if (sum==0){if ((cnt&1)!=w)ans=0;}
			else ans=ans*poww(2,sum-1)%Mod;
		}
		res=(res+ans)%Mod;
	}
	cout<<res<<'\n';
}

void work3()
{
	int res=0;
	for (int w=0;w<2;w++)
	{
		int ans=1;
		for (int j=1;j<=m;j++)
		{
			int cnt=0,sum=0;
			for (int i=1;i<=n;i++)
				if (a[i][j]==2)sum++;
				else cnt+=a[i][j];
			if (sum==0){if ((cnt&1)!=w)ans=0;}
			else ans=ans*poww(2,sum-1)%Mod;
		}
		res=(res+ans)%Mod;
	}
	cout<<res<<'\n';
}

void work4()
{
	for (int i=1;i<=n+m;i++)f[i]=i; 
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (a[i][j]==2)
				sz[i]++,f[find(i)]=find(j+n);
			else b[i]^=a[i][j],c[j]^=a[i][j];
		}
	for (int i=1;i<=n+m;i++)
		v[find(i)].pb(i);
	int ans=0;
	for (int w=0;w<2;w++)
	{
		int res=1;
		for (int i=1;i<=n+m;i++)
		{
			if (!v[i].size())continue;
			int s1=v[i].size(),s2=0,s=0;
			for (auto x:v[i])
			{
				s2+=sz[x];
				if (x<=n)s^=b[x];
				else s^=c[x-n];
			}
			if (s1&1)
			{
				if (s==w)res=res*poww(2,s2-s1+1)%Mod;
				else res=0;
			}
			else
			{
				if (s==0)res=res*poww(2,s2-s1+1)%Mod;
				else res=0;
			}
		}
		ans=(ans+res)%Mod;
	}
	cout<<ans<<'\n';
}

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		cin>>s;
		for (int j=0;j<m;j++)
			if (s[j]=='1')a[i][j+1]=1;
			else if (s[j]=='?')a[i][j+1]=2;
	}
	int c1=n&1,c2=m&1;
	if (!c1&&!c2)work1();
	if (!c1&&c2)work2();
	if (c1&&!c2)work3();
	if (c1&&c2)work4();
	return 0;
}