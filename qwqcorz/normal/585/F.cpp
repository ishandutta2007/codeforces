#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;
const int D=55;
const int p=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

void add(int &x,int y){x+=y;if (x>=p) x-=p;}
int n,d;
namespace AC_automation
{
	int cnt=0;
	struct node
	{
		bool end;
		int son[10],fail;
	}t[N*D];
	void insert(char *a,int n)
	{
		int now=0;
		for (int i=0;i<n;i++)
		{
			if (!t[now].son[a[i]-'0']) t[now].son[a[i]-'0']=++cnt;
			now=t[now].son[a[i]-'0'];
		}
		t[now].end=1;
	}
	void build()
	{
		queue<int>q;
		for (int i=0;i<=9;i++) if (t[0].son[i]) q.push(t[0].son[i]);
		while (!q.empty())
		{
			int now=q.front(); q.pop();
			for (int i=0;i<=9;i++)
			if (t[now].son[i])
			{
				t[t[now].son[i]].fail=t[t[now].fail].son[i];
				q.push(t[now].son[i]);
			}
			else t[now].son[i]=t[t[now].fail].son[i];
		}
	}
}
using namespace AC_automation;
char s[N],l[D],r[D];
int dp[D][N*D][2][2];
int calc(char *a)
{
	memset(dp,0,sizeof(dp));
	dp[0][0][0][1]=1;
	for (int i=1;i<=d;i++)
	for (int j=0;j<=cnt;j++)
	for (int x=0;x<=1;x++)
	for (int y=0;y<=1;y++)
	if (dp[i-1][j][x][y])
	for (int k=0;k<=(y?a[i]-'0':9);k++)
	add(dp[i][t[j].son[k]][x||t[t[j].son[k]].end][y&&k==a[i]-'0'],dp[i-1][j][x][y]);
	int ret=0;
	for (int i=0;i<=cnt;i++)
	for (int j=0;j<=1;j++)
	add(ret,dp[d][i][1][j]);
	return ret;
}

signed main()
{
	scanf("%s%s%s",s+1,l+1,r+1);
	n=strlen(s+1),d=strlen(l+1);
	for (int i=1;i+d/2-1<=n;i++) insert(s+i,d/2);
	build();
	{
		int tmp=d;
		while (l[tmp]=='0') tmp--;
		l[tmp]--;
		while (++tmp<=d) l[tmp]='9';
	}
	print((calc(r)-calc(l)+p)%p);
	
	return 0;
}