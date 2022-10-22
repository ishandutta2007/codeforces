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

const int M=(1<<13)+10;
bool vis[M][M],a[M][M];
vector<int>v[M];

signed main()
{
	int n=read();a[0][0]=1;
	for (int i=1;i<=5000;i++)vis[i][i]=1,v[i].pb(i);
	while(n--)
	{
		int x=read();
		for (int i=0;i<v[x].size();i++)
		{
			int y=v[x][i];a[x][y]=1;
			for (int j=x+1;j<=5000;j++)
			{
				if (vis[j][j^y])break;
				vis[j][j^y]=1,v[j].pb(j^y);
			}
		}v[x].clear();
	}int cnt=0;
	for (int i=0;i<(1<<13);i++)
		for (int j=0;j<(1<<13);j++)
			a[0][j]|=a[i][j];
	for (int i=0;i<(1<<13);i++)
		if (a[0][i])cnt++;cout<<cnt<<endl;
	for (int i=0;i<(1<<13);i++)
		if (a[0][i])cout<<i<<' ';
	return 0;
}