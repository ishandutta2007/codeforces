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

const int M=110;
int n,f[M][M][2][2],vis[M][M][2][2];

int dfs(int x,int y,int t1,int t2)
{
	if (vis[x][y][t1][t2])return f[x][y][t1][t2];
	vis[x][y][t1][t2]=1;
	if (x+y==0)return f[x][y][t1][t2]=(t1^1);
	if (t2==0)
	{
		int tmp=0;
		if (x!=0)tmp|=dfs(x-1,y,t1^1,t2^1);
		if (y!=0)tmp|=dfs(x,y-1,t1,t2^1);
		return f[x][y][t1][t2]=tmp;
	}
	else
	{
		int tmp=1;
		if (x!=0)tmp&=dfs(x-1,y,t1,t2^1);
		if (y!=0)tmp&=dfs(x,y-1,t1,t2^1);
		return f[x][y][t1][t2]=tmp;
	}
}

void solve()
{
	int n=read(),cnt=0;
	for (int i=1;i<=n;i++)cnt+=(read()%2==0)?0:1;
	int x=cnt,y=n-cnt;
	//x 1 y 0
	if (dfs(x,y,0,0))puts("Alice");
	else puts("Bob");
}

signed main()
{
	WT solve();
	return 0;
}