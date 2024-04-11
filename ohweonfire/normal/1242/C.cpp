// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

int n,last[1<<15];
bool can[1<<15],dp[1<<15];
LL s[20];
vector<LL> a[20];
int mark[15][5111];
pii nxt[15][5111],bg[1<<15],ans[15];
map<LL,pii> pos;

void addq(int msk)
{
	pii cur=bg[msk];
	while(msk)
	{
		ans[cur.ff].ff=a[cur.ff][cur.ss];
		ans[nxt[cur.ff][cur.ss].ff].ss=cur.ff;
		msk^=(1<<cur.ff);
		cur=nxt[cur.ff][cur.ss];
	}
}

void dfs(int x)
{
	if(!x)return;
	addq(last[x]);
	dfs(x^last[x]);
}

int main()
{
	get1(n);
	LL sum=0;
	for(int i=0;i<n;i++)
	{
		int sz;
		LL x;
		get1(sz);
		while(sz--)
		{
			get1(x);
			a[i].pb(x);
			sum+=x;
			s[i]+=x;
		}
		for(int j=0;j<(int)a[i].size();j++)pos[a[i][j]]=mp(i,j);
	}
	if(sum%n)
	{
		puts("No");
		return 0;
	}
	
	sum/=n;
	for(int i=0;i<n;i++)for(int j=0;j<(int)a[i].size();j++)
	{
		LL need=sum-(s[i]-a[i][j]);
		if(pos.find(need)==pos.end())nxt[i][j]=mp(-1,-1);
		else nxt[i][j]=pos[need];
	}
	
	int timer=0;
	for(int i=0;i<n;i++)for(int j=0;j<(int)a[i].size();j++)if(!mark[i][j])
	{
		timer++;
		pii cur=mp(i,j);
		while(cur.ff!=-1&&!mark[cur.ff][cur.ss])
		{
			mark[cur.ff][cur.ss]=timer;
			cur=nxt[cur.ff][cur.ss];
		}
		if(cur.ff==-1||mark[cur.ff][cur.ss]!=timer)continue;
		int msk=0;
		bool ok=1;
		pii cur2=cur;
		while(true)
		{
			if((msk>>cur.ff)&1)
			{
				ok=0;
				break;
			}
			msk|=1<<cur.ff;
			cur=nxt[cur.ff][cur.ss];
			if(cur==cur2)break;
		}
		if(ok)
		{
			bg[msk]=cur;
			can[msk]=1;
		}
	}
	
	dp[0]=1;
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=i;j;j=(j-1)&i)if(can[j]&dp[i^j])
		{
			dp[i]|=(can[j]&dp[i^j]);
			last[i]=j;
		}
	}
	if(dp[(1<<n)-1])
	{
		puts("Yes");
		dfs((1<<n)-1);
		for(int i=0;i<n;i++)printf("%d %d\n",ans[i].ff,ans[i].ss+1);
	}
	else puts("No");
	
	return 0;
}