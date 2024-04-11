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
int n,k,p[M],t[M],sz[M],f[M],b[M];
vector<int>v;

int find(int x){return x==f[x]?x:f[x]=find(f[x]);}

bool check(int x)
{
	for (int i=1;i<=n;i++)f[i]=i,sz[i]=0;
	for (int i=1;i<=n;i++)b[i]=p[(i+x)%n==0?n:(i+x)%n];
	for (int i=1;i<=n;i++)f[find(b[i])]=find(i);
	int res=0;
	for (int i=1;i<=n;i++)sz[find(i)]++;
	for (int i=1;i<=n;i++)
	{
		if (sz[i]==0)continue;
		res+=sz[i]-1;
	}return res<=k;
}

signed main()
{
	WT
	{
		n=read(),k=read();v.clear();
		for (int i=1;i<=n;i++)p[i]=read(),t[(i-p[i]+n)%n]++;
		for (int i=0;i<n;i++)
			if (t[i]>=n-2*k)
				if (check(i))v.pb(i);
		cout<<v.size()<<' ';
		for (int i=0;i<v.size();i++)cout<<v[i]<<' ';
		puts("");
	}
	return 0;
}