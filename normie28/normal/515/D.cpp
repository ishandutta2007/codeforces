#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "travel.inp"
#define FILE_OUT "travel.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define _for(i,a,b) for(int i=(a);i<(b);++i)
#define ms(a) memset(a,0,sizeof(a))
#define ms_inf(a) memset(a,0x3f,sizeof(a))
#define ms_ninf(a) memset(a,0xcf,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
const double eps = 1e-10;
const double INF=1e8;
const double PI = acos(-1.0);
const int maxn=2010;
int m,n;
char c[maxn][maxn];
queue<pair<int,int> >q;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
bool va(int i,int j)
{
	return i>=0&&i<n&&j>=0&&j<m;
}
int cal(int i,int j)
{
	int cnt=0;
	_for(t,0,4)
	{
		if(va(i+dx[t],j+dy[t]))
		{
			if(c[i+dx[t]][j+dy[t]]=='.')++cnt;
		}
	}
	return cnt;
}
int main()
{
	cin>>n>>m;
	_for(i,0,n)scanf("%s",c[i]);
	_for(i,0,n)_for(j,0,m)
	{
		if(c[i][j]=='.'&&cal(i,j)==0)
		{
			puts("Not unique");return 0;
		}
		if(c[i][j]=='.'&&cal(i,j)==1)q.push(mp(i,j));
	}
	while(!q.empty())
	{
		pair<int,int>e=q.front();q.pop();
		int i=e.first,j=e.second;
		if(c[i][j]!='.'||cal(i,j)!=1)continue;
		int ni,nj;
		int re;
		_for(t,0,4)
		{
			if(va(i+dx[t],j+dy[t])&&c[i+dx[t]][j+dy[t]]=='.')ni=i+dx[t],nj=j+dy[t],re=t;
		}
		vector<pair<int,int> >rele;
		_for(t,0,4)
		{
			if(va(i+dx[t],j+dy[t])&&c[i+dx[t]][j+dy[t]]=='.')rele.pb(mp(i+dx[t],j+dy[t]));
			if(va(ni+dx[t],nj+dy[t])&&c[ni+dx[t]][nj+dy[t]]=='.')rele.pb(mp(ni+dx[t],nj+dy[t]));
		}
		if(re==0)c[i][j]='^',c[ni][nj]='v';
		if(re==1)c[i][j]='<',c[ni][nj]='>';
		if(re==2)c[i][j]='v',c[ni][nj]='^';
		if(re==3)c[i][j]='>',c[ni][nj]='<';
		_for(t,0,rele.size())
		{
			if(c[rele[t].first][rele[t].second]=='.'&&cal(rele[t].first,rele[t].second)==1)q.push(rele[t]);
		}
	}
	_for(i,0,n)_for(j,0,m)
	{
		if(c[i][j]=='.')
		{
			puts("Not unique");return 0;
		}
	}
	_for(i,0,n)
	{
		_for(j,0,m)
		{
			printf("%c",c[i][j]);
		}
		puts("");
	}
}