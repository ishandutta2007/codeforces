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

const int maxn=1000111;
const int dx[]={-1,-1,-1,0,0,1,1,1};
const int dy[]={-1,0,1,-1,1,-1,0,1};

int n,m;
template<typename T> void resize(T&v,int val=0)
{
	v.resize(n+2);
	for(int i=0;i<n+2;i++)v[i].resize(m+2,val);
}
vector<vi> f,d,sv;
queue<pii> q;
char s[maxn];

bool check(int val)
{
	for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)sv[i][j]=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(d[i][j]>=val)
	{
		sv[i-val+1][j-val+1]++;
		sv[i-val+1][j+val]--;
		sv[i+val][j-val+1]--;
		sv[i+val][j+val]++;
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
	{
		sv[i][j]+=sv[i-1][j]+sv[i][j-1]-sv[i-1][j-1];
		if(f[i][j]&&!sv[i][j])return false;
	}
	return true;
}

int main()
{
	get2(n,m);
	resize(f);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)if(s[j]=='.')f[i][j]=0;else f[i][j]=1;
	}
	resize(d,-1);
	resize(sv);
	for(int i=0;i<=n+1;i++)for(int j=0;j<=m+1;j++)if(!f[i][j])
	{
		q.push(mp(i,j));
		d[i][j]=0;
	}
	
	int lb=1,rb;
	while(!q.empty())
	{
		int x=q.front().ff,y=q.front().ss;q.pop();
		rb=d[x][y]+1;
		for(int k=0;k<8;k++)
		{
			int nx=x+dx[k],ny=y+dy[k];
			if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&d[nx][ny]==-1)
			{
				d[nx][ny]=d[x][y]+1;
				q.push(mp(nx,ny));
			}
		}
	}
	while(lb<rb-1)
	{
		int mid=(lb+rb)>>1;
		if(check(mid))lb=mid;
		else rb=mid;
	}
	printendl(lb-1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)if(d[i][j]>=lb)putchar('X');
		else putchar('.');
		puts("");
	}
	return 0;
}