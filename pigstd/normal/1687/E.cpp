#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=1e5+10;
int n,a[M],vis[M];
vector<pii>v;

vector<int>operator +(vector<int>a,vector<int>b)
{
	for (auto y:b)a.pb(y);
	return a;
}

vector<int>operator -(vector<int>a,int b)
{
	vector<int>c;
	for (auto x:a)if (x!=b)c.pb(x);
	return c;
}

vector<int>work(vector<pii>x)
{
	int tmp=0;vector<int>res;
	if (x.size()==0)return res;
	memset(vis,0,sizeof(vis));
	tmp=x[0].x;vis[x[0].y]=1;
	for (int i=2;i<=tmp;i++)
	{
		if (tmp%i)continue;
		while(tmp%i==0)tmp/=i;
		pii qwq=mp(1000,0);
		for (auto y:x)
		{
			int w=0,k=y.x;
			while(k%i==0)k/=i,w++;
			qwq=min(qwq,mp(w,y.y));
		}
		vis[qwq.y]=1;
	}
	int d1=0;
	for (auto y:x)d1=__gcd(d1,y.x);
	for (auto y:x)if (vis[y.y])res.pb(y.y);
	for (auto x:res)
	{
		int d2=0;
		for (auto y:res)
			if (y!=x)d2=__gcd(d2,a[y]);
		if (d2==d1)return vis[x]=0,res-x;
	}
	assert(res.size()<=7);
	return res;
}

void solve(vector<int>v)
{
	sort(v.begin(),v.end());
	int n=v.size();
//	cout<<n<<'\n';
//	for (auto x:v)cout<<x<<' ';
//	puts("");
	int sz=0;
	for (int i=1;i<(1<<n);i++)
	{
		int c=__builtin_popcount(i);
		sz+=abs(c-2);
	}
	cout<<sz<<"\n";
	for (int i=1;i<(1<<n);i++)
	{
		int c=__builtin_popcount(i),opt=0;
		c=(c&1?-1:1)*(c-2);
		if (c==0)continue;
		if (c<0)opt=1,c=-c;
		vector<int>p;
		for (int j=0;j<n;j++)
			if ((i>>j)&1)p.pb(v[j]);
		while(c--)
		{
			cout<<opt<<' '<<p.size()<<' ';
			for (auto x:p)cout<<x<<' ';
			puts("");
		}
	}
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read(),v.pb(mp(a[i],i));
	vector<int>x=work(v);
	v.clear();
	for (int i=1;i<=n;i++)if (!vis[i])v.pb(mp(a[i],i));
	memset(vis,0,sizeof(vis));
	x=x+work(v);
	solve(x);
	return 0;
}