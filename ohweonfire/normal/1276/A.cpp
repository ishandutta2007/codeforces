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

const int maxn=150111;

char s[maxn];
int n;
string vs[]={"one","on","o","two","tw","t",""};
int go[7][26],dp[maxn][7],last[maxn][7];

void upd(int x,int y,int v,int lastv)
{
	if(vs[y]=="one"||vs[y]=="two")return;
	if(dp[x][y]>v)
	{
		dp[x][y]=v;
		last[x][y]=lastv;
	}
}

void goo(int x,int y)
{
	if(x==1)return;
	goo(x-1,last[x][y]);
	if(dp[x][y]!=dp[x-1][last[x][y]])printf("%d ",x-1);
}

void solve()
{
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n+1;i++)for(int j=0;j<7;j++)dp[i][j]=inf;
	dp[1][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<7;j++)if(dp[i][j]!=inf)
		{
			upd(i+1,j,dp[i][j]+1,j);
			upd(i+1,go[j][s[i]-'a'],dp[i][j],j);
		}
	}
	int mn=min_element(dp[n+1],dp[n+1]+7)-dp[n+1];
	printendl(dp[n+1][mn]);
	goo(n+1,mn);
	puts("");
}

int main()
{
	sort(vs,vs+7);
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<26;j++)
		{
			string now=vs[i]+char(j+'a');
			while(true)
			{
				int piv=-1;
				for(int k=0;k<7;k++)if(now==vs[k])piv=k;
				if(piv!=-1)
				{
					go[i][j]=piv;
					break;
				}
				now=now.substr(1);
			}
		}
	}
	
	int tc;
	get1(tc);
	while(tc--)solve();
	return 0;
}