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

int n,tn,a[100111];
int dist[1<<16],q[1<<16],pre[1<<16],d1[1<<16],d2[1<<16],d3[1<<16],fr,rr;

vector<pair<pii,int> >cmd;
void perform(int x,int y,int z)
{
	cmd.pb(mp(mp(x+1,y+1),z+1));
	a[x]^=1;a[y]^=1;a[z]^=1;
}
int main()
{
	n=16;
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)
	{
		int k=j+j-i;
		if(k<n)
		{
			int msk=(1<<i)|(1<<j)|(1<<k);
			d1[msk]=i;d2[msk]=j;d3[msk]=k;
		}
	}
	
	n=12;
	memset(dist,-1,sizeof(dist));memset(pre,-1,sizeof(pre));
	fr=rr=0;
	for(int i=0;i<(1<<n/4);i++)
	{
		q[rr++]=i;
		dist[i]=0;
	}
	for(;fr<rr;fr++)
	{
		int x=q[fr];
		for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)
		{
			int k=j+j-i;
			if(k>=n)continue;
			int nx=x^(1<<i)^(1<<j)^(1<<k);
			if(dist[nx]==-1)
			{
				dist[nx]=dist[x]+1;
				pre[nx]=x;
				q[rr++]=nx;
			}
		}
	}
	
	get1(n);tn=n;
	for(int i=0;i<n;i++)get1(a[i]);
	while(n>16)
	{
		int msk=0;
		for(int i=n-12;i<n;i++)msk|=(a[i]<<i-n+12);
		while(pre[msk]!=-1)
		{
			int nxt=pre[msk]^msk;
			perform(n-12+d1[nxt],n-12+d2[nxt],n-12+d3[nxt]);
			msk=pre[msk];
		}
		n-=9;
	}
	
	memset(dist,-1,sizeof(dist));memset(pre,-1,sizeof(pre));
	fr=rr=0;q[rr++]=0;dist[0]=0;
	for(;fr<rr;fr++)
	{
		int x=q[fr];
		for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)
		{
			int k=j+j-i;
			if(k>=n)continue;
			int nx=x^(1<<i)^(1<<j)^(1<<k);
			if(dist[nx]==-1)
			{
				dist[nx]=dist[x]+1;
				pre[nx]=x;
				q[rr++]=nx;
			}
		}
	}
	
	int msk=0;
	for(int i=0;i<n;i++)msk|=(a[i]<<i);
	if(dist[msk]==-1)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	while(pre[msk]!=-1)
	{
		int nxt=pre[msk]^msk;
		perform(d1[nxt],d2[nxt],d3[nxt]);
		msk=pre[msk];
	}
	assert((int)cmd.size()<=tn/3+12);
	printf("%d\n",(int)cmd.size());
	for(int i=0;i<(int)cmd.size();i++)printf("%d %d %d\n",cmd[i].ff.ff,cmd[i].ff.ss,cmd[i].ss);
	for(int i=0;i<n;i++)assert(a[i]==0);
	return 0;
}