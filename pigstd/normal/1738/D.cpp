#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--)
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
inline void ckmax(int &a,int b){a=(a>b?a:b);}
inline void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=1e5+10;
int n,b[M],s[M],a[M],c[M],vis[M];
vector<int>v[M];

void solve()
{
	int n=read(),k=0;
	for (int i=0;i<=n+1;i++)s[i]=0,vis[i]=0,a[i]=0,v[i].clear();
	for (int i=1;i<=n;i++)b[i]=read(),s[b[i]]++,v[b[i]].pb(i);
	int S=s[0];
	for (int i=1;i<=n;i++)
	{
		S+=s[i];
		if (S==n-i){k=i;break;}
	}
	cout<<k<<'\n';
	int pos=0;
	if (v[n+1].size())pos=n+1;
	int tot=0;
	while(tot!=n)
	{
		int tmp=v[pos][0];
		for (auto x:v[pos])
			if (v[x].size())tmp=x;
		for (auto x:v[pos])
			if (x!=tmp)a[++tot]=x;
		a[++tot]=tmp;pos=tmp;
	}
	for (int i=1;i<=n;i++)cout<<a[i]<<(i==n?'\n':' ');
}

signed main()
{
	WT solve();
	return 0;
}