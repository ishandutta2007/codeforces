// By: Little09
// Problem: E. Fair Share
// Contest: Codeforces - Codeforces Round #770 (Div. 2)
// URL: https://codeforces.com/contest/1634/problem/E
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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

const ll inf=1000000000000000000; 
//const ll mod=998244353;
//const ll mod=1000000007;

const int N=500005;
int n,m; 

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
	int x,id,ans;
};

vector<point>a[N];
vector<int>ans[N];
bool cmp(point x,point y)
{
	return x.x<y.x;
}
int b[N],cnt;

map<int,int>q;

int t[N],nxt[N],h[N],tot=1,id[N],used[N];
inline void add(int x,int y,int z)
{
	tot++;
	t[tot]=y;
	id[tot]=z;
	nxt[tot]=h[x];
	h[x]=tot;
}

bool ttt[N];

void dfs(int s,int x,int e,int st)
{
	if (x==s&&st) return;
	int pre=0;
	for (int i=h[x];i;i=nxt[i])
	{
		if (used[i])
		{
			nxt[pre]=nxt[i];
			pre=i;
			continue;
		}
		used[i]=1;
		used[i^1]=1;
		//cout << x << " " << t[i] << endl;
		ans[max(t[i],x)-cnt][id[i]]=e;
		dfs(s,t[i],e*-1,1);
		pre=i;
		return;
	}
	ttt[s]=1;
}

int E[N];

int main()
{
	m=read();
	for (int i=1;i<=m;i++)
	{
		b[i]=read();
		for (int j=0;j<b[i];j++)
		{
			int x=read();
			if (q[x]!=0) x=q[x];
			else cnt++,q[x]=cnt,x=cnt;
			point y;
			y.x=x,y.id=j,y.ans=0;
			a[i].push_back(y);
			ans[i].push_back(0);
			E[x]++;
		}
		sort(a[i].begin(),a[i].end(),cmp);
	}
	for (int i=1;i<=cnt;i++)
	{
		if (E[i]%2==1)
		{
			printNO;
			return 0;
		}
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<b[i];j++)
		{
			if (a[i][j].x==a[i][j-1].x)
			{
				if (a[i][j-1].ans!=0) continue;
				a[i][j-1].ans=-1,a[i][j].ans=1;
			}
		}
		for (int j=0;j<b[i];j++)
		{
			if (a[i][j].ans==0)
			{
				add(a[i][j].x,cnt+i,a[i][j].id);
				add(cnt+i,a[i][j].x,a[i][j].id);
			}
			else
			{
				ans[i][a[i][j].id]=a[i][j].ans;
			}
		}
	}
	for (int i=1;i<=cnt;i++)
	{
		while (ttt[i]==0) dfs(i,i,-1,0);
	}
	printYES;
	for (int i=1;i<=m;i++)
	{
		for (int j=0;j<b[i];j++)
		{
			if (ans[i][j]==-1) printf("L");
			else printf("R");
		}
		printf("\n");
	}
	return 0;
}