// By: Little09
// Problem: D. Big Brush
// Contest: Codeforces - Codeforces Round #771 (Div. 2)
// URL: https://codeforces.com/contest/1638/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes puts("Yes")
#define printYES puts("YES")
#define printNo puts("No")
#define printNO puts("NO")
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=1005;
int n,m; 
int a[N][N];

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
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
inline char readchar()
{
	char C=getchar();
    while (C<33||C>126) C=getchar();
    return C;
}
inline int raed(){return read();}
struct point
{
	int x,y,col;
};
queue<point>q;
int ans[N*N][3],cnt;

int check(int x,int y)
{
	if (x<1||y<1||x>=n||y>=m) return 0;
	int u=-1;
	for (int i=0;i<=1;i++)
	{
		for (int j=0;j<=1;j++)
		{
			if (a[i+x][y+j]!=0) 
			{
				if (u==-1) u=a[i+x][y+j];
				else if (u!=a[i+x][y+j]) return 0;
			}
		}
	}
	if (u==-1) return 0;
	return u;
}

inline void update(int x,int y)
{
	if (x<1||y<1||x>=n||y>=m) return;
	int tmp=check(x,y);
	if (tmp>0) 
	{
		q.push((point){x,y,tmp});
	}
}

int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			a[i][j]=read();
		}
	}
	for (int i=1;i<n;i++)
	{
		for (int j=1;j<n;j++)
		{
			int x=check(i,j);
			if (x) q.push((point){i,j,x});
		}
	}
	while (!q.empty())
	{
		point u=q.front();
		q.pop();
		if (check(u.x,u.y)==0) continue;
		++cnt;
		ans[cnt][0]=u.x,ans[cnt][1]=u.y,ans[cnt][2]=u.col;
		for (int i=0;i<=1;i++)
		{
			for (int j=0;j<=1;j++)
			{
				a[i+u.x][j+u.y]=0;
			}
		}
		for (int i=-1;i<=1;i++)
		{
			for (int j=-1;j<=1;j++)
			{
				update(i+u.x,j+u.y);
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (a[i][j]!=0)
			{
				printf("-1");
				return 0;
			}
		}
	}
	cout << cnt << endl;
	for (int i=cnt;i>=1;i--) printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
	return 0;
}