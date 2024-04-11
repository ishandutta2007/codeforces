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

const int M=1010;
int n,a[M][M],vis[M][M],res;

void add(int x,int y)
{
	vis[x-1][y]^=1,vis[x+1][y]^=1,
	vis[x][y-1]^=1,vis[x][y+1]^=1;
	res^=a[x][y];
}

void solve()
{
	n=read(),res=0;
	for (int i=1;i<=n;i++)for (int j=1;j<=n;j++)a[i][j]=read();
	if (n==2)return cout<<(a[1][1]^a[1][2])<<'\n',void(); 
	if (n%4==0)for (int i=2;i<=n;i+=4)add(1,i),add(1,i+1);
	else for (int i=1;i<=n;i+=4)add(1,i),add(1,i+1);
	for (int i=2;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			if (vis[i][j])continue;
			if (j==n||vis[i][j+1])add(i+1,j),add(i+2,j);
			else add(i+1,j),add(i+1,j+1);
		}
	cout<<res<<'\n';
	for (int i=0;i<=n+1;i++)for (int j=0;j<=n+1;j++)vis[i][j]=0;
}

signed main()
{
	WT solve();
	return 0;
}