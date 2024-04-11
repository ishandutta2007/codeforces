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

const int Mod=998244353;
const int M=1e5+10;
int n,f[M],sz[M],res=1;

int find(int x){return f[x]==x?x:f[x]=find(f[x]);}

signed main()
{
	n=read();
	for (int i=1;i<n;i++)res=res*(2*i-1)%Mod;
	cerr<<res<<'\n';
	for (int i=1;i<=n;i++)f[i]=i,sz[i]=1;
	for (int i=1;i<n;i++)
	{
		int u=find(read()),v=find(read());
		res=res*sz[u]%Mod*sz[u]%Mod*sz[v]%Mod*sz[v]%Mod;
		f[u]=v,sz[v]+=sz[u];
	}
	cout<<res<<'\n';
	return 0;
}