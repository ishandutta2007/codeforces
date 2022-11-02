#include<bits/stdc++.h>
using namespace std;
clock_t __t=clock();
#define rep(i,x,y) for (int i=(x);i<=(y);++i)
#define drep(i,y,x) for (int i=(y);i>=(x);--i)
#define temp template<typename T>
temp bool chkmin(T &x,T y){return x>y?x=y,1:0;}
temp bool chkmax(T &x,T y){return x<y?x=y,1:0;}
#define ll long long
#define db double
void file()
{
	#ifdef NTFAKIOI
	freopen("a.in","r",stdin);
	#endif
}
void chktime()
{
	#ifdef NTFAKIOI
	cout<<1.0*(clock()-__t)/1000;
	#endif
}
temp void read(T &x)
{
	x=0;char ch=getchar(),t=0;
	while (ch>'9'||ch<'0') t|=(ch=='-'),ch=getchar();
	while (ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	x=(t?-x:x);
}
#define go(x) for (int i=head[x];i;i=edge[i].nxt)
#define pii pair<int,int>
#define fir first
#define sec second
#define MP make_pair
#define sz 1010101

int n;
int son[sz][3];
#define ls son[x][1]
#define rs son[x][2]
int type[sz]; // and, or, xor, not, in

int ans[sz][2];
int dp[sz];

void dfs1(int x)
{
	if (type[x]==5) return;
	dfs1(ls);if (type[x]!=4) dfs1(rs);
	if (type[x]==1) dp[x]=dp[ls]&dp[rs];
	else if (type[x]==2) dp[x]=dp[ls]|dp[rs];
	else if (type[x]==3) dp[x]=dp[ls]^dp[rs];
	else dp[x]=!dp[ls];
}
void dfs2(int x)
{
	if (x==1) ans[x][0]=0,ans[x][1]=1;
	if (type[x]==5) return;
	if (type[x]==4) ans[ls][0]=ans[x][1],ans[ls][1]=ans[x][0];
	else if (type[x]==1) ans[ls][0]=ans[rs][0]=ans[x][0],ans[ls][1]=ans[x][dp[rs]],ans[rs][1]=ans[x][dp[ls]];
	else if (type[x]==2) ans[ls][1]=ans[rs][1]=ans[x][1],ans[ls][0]=ans[x][dp[rs]],ans[rs][0]=ans[x][dp[ls]];
	else ans[ls][0]=ans[x][dp[rs]],ans[rs][0]=ans[x][dp[ls]],ans[ls][1]=ans[x][dp[rs]^1],ans[rs][1]=ans[x][dp[ls]^1];
	if (type[x]==4) dfs2(ls);
	else dfs2(ls),dfs2(rs);
}

int main()
{
	file();
	read(n);
	rep(i,1,n)
	{
		string s;cin>>s;
		int X,Y;read(X);int x=i;
		if (s[0]=='A'||s[0]=='O'||s[0]=='X')
		{
			read(Y);
			ls=X,rs=Y;
		} 
		else if (s[0]=='N') ls=X;
		else dp[i]=X;
		type[i]=(s[0]=='A'?1:(s[0]=='O'?2:(s[0]=='X'?3:(s[0]=='N'?4:5))));
	}
	dfs1(1);dfs2(1);
	rep(i,1,n) if (type[i]==5) putchar('0'+ans[i][!dp[i]]);
	return 0;
}