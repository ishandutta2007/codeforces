#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
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

const int M=3e5+10;
const int N=1e6+10;
int n,a[M],q,f[N],ff[N],prime[N],b[M],cnt;
map<int,int>t[M];
vector<int>v; 

int find(int x){return ff[x]==x?x:ff[x]=find(ff[x]);}

void init(int n)
{
	for (int i=2;i<=n;i++)
	{
		if (f[i])continue;
		prime[++cnt]=i,f[i]=cnt;
		for (int j=i*i;j<=n;j+=i)
			f[j]=1;
	}
	for (int i=1;i<=cnt;i++)ff[i]=i;
}

void get(int x)
{
	for (int i=1;prime[i]*prime[i]<=x;i++)
	{
		if (x%prime[i]==0)
		{
			v.pb(i);
			while(x%prime[i]==0)
				x/=prime[i];
		}
	}
	if (x!=1)v.pb(f[x]);
}

signed main()
{
	n=read(),q=read();
	init(1e6);
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		v.clear();get(a[i]);
		for (int j=1;j<v.size();j++)
			ff[find(v[j])]=find(v[0]);
//		for (int j=0;j<v.size();j++)cout<<v[j]<<' ';puts("");
		b[i]=v[0];
	}
	for (int i=1;i<=n;i++)b[i]=find(b[i]);
	for (int i=1;i<=n;i++)
	{
		v.clear();get(a[i]+1),get(a[i]);
		for (int j=0;j<v.size();j++)
			for (int k=j+1;k<v.size();k++)
				t[find(v[j])][find(v[k])]=t[find(v[k])][find(v[j])]=i;
	}
	while(q--)
	{
		int x=read(),y=read();
		if (b[x]==b[y])puts("0");
		else if (t[b[x]][b[y]])puts("1");
		else puts("2");
	}
	return 0;
}