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
typedef vector<int> vi;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

const int mod=1e9+7;
inline void add(int&x,int y){x+=y;if(x>=mod)x-=mod;}

const int maxn=1111;
const int maxm=55;
const int N=10;
const int maxv=50111;

int go[maxv][N],tot,rt;
bool kill[maxv];

namespace ac
{
	int q[maxv],fr,rr,fail[maxv];
	void construct()
	{
		fr=rr=0;q[rr++]=rt;
		for(;fr<rr;fr++)
		{
			int x=q[fr];
			for(int i=0;i<N;i++)if(go[x][i])
			{
				int&f=fail[go[x][i]];
				if(x==rt)f=x;
				else
				{
					f=fail[x];
					while(f!=rt&&!go[f][i])f=fail[f];
					if(go[f][i])f=go[f][i];
				}
				q[rr++]=go[x][i];
			}
		}
		for(int i=0;i<N;i++)if(!go[rt][i])go[rt][i]=rt;
		for(int t=0;t<rr;t++)
		{
			int x=q[t];
			for(int i=0;i<N;i++)if(!go[x][i])go[x][i]=go[fail[x]][i];
		}
		tot++;for(int i=0;i<N;i++)go[tot][i]=tot;
		for(int p=1;p<tot;p++)for(int c=0;c<N;c++)if(kill[go[p][c]])go[p][c]=tot;
//		for(int p=1;p<=tot;p++)for(int c=0;c<N;c++)printf("p= %d c= %d go= %d\n",p,c,go[p][c]);
	}
};

char s[maxn],t[maxn];
int n,m,last,tx[maxn],ty[maxn];

void getv(int*d)
{
	scanf("%s",t);m=strlen(t);
	for(int i=0;i<m;i++)d[i]=t[m-i-1]-'0';
}

int dp[55][maxv][2];
int calc(int*d)
{
	memset(dp,0,sizeof(dp));dp[0][rt][0]=1;
	for(int l=0;l<m;l++)for(int p=1;p<=tot;p++)for(int diff=0;diff<2;diff++)if(dp[l][p][diff])
	{
		int ub=(diff?9:d[l]);
		for(int nxt=0;nxt<=ub;nxt++)
			add(dp[l+1][go[p][nxt]][diff|(nxt!=ub)],dp[l][p][diff]);
	}
	return (dp[m][tot][0]+dp[m][tot][1])%mod;
}

int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	getv(tx);
	getv(ty);
	tx[0]--;int cur=0;
	while(tx[cur]<0)
	{
		tx[cur]+=10;
		tx[++cur]--;
	}
	reverse(tx,tx+m);reverse(ty,ty+m);
	
	tot=rt=1;
	for(int i=1;i<=n-m/2+1;i++)
	{
		int cur=rt;
		for(int j=0;j<m/2;j++)
		{
			if(!go[cur][s[i+j]-'0'])go[cur][s[i+j]-'0']=++tot;
			cur=go[cur][s[i+j]-'0'];
		}
		kill[cur]=1;
	}
	ac::construct();
	
	printendl((calc(ty)-calc(tx)+mod)%mod);
	return 0;
}