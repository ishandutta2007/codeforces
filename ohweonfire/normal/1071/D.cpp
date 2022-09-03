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

const int maxn=1000111;
int mn[maxn],dv[maxn],eq[maxn],p[maxn],tot;
int getf(int x,int&dv,vector<int>&t)
{
	dv=1;
	t.clear();
	while(x>1)
	{
		int pp=mn[x],c=0;
		while(x%pp==0)
		{
			x/=pp;
			c++;
		}
		t.pb(c);
		dv*=c+1;
	}
	sort(t.begin(),t.end());reverse(t.begin(),t.end());
	vector<int> nt=t;
	int ret=1;
	for(int i=0;i<(int)t.size();i++)while(nt[i]--)ret*=p[i];
	return ret;
}

const int magic=300;
int dist[300][1111],id[maxn],cnt;

int dp[1111],ndp[1111];
void do_dp(int*ans,vector<int>&fc)
{
	while(fc.size()<22)fc.pb(0);
	memset(dp,inf,sizeof(dp));
	dp[1]=0;
	for(int i=0;i<(int)fc.size();i++)
	{
		memset(ndp,inf,sizeof(ndp));
		for(int j=0;j<22;j++)
		{
			for(int k=magic/(j+1);k>=1;k--)
				ndp[k*(j+1)]=min(ndp[k*(j+1)],dp[k]+abs(fc[i]-j));
		}
		swap(dp,ndp);
	}
	for(int i=1;i<=magic;i++)ans[i]=dp[i];
}

int main()
{
	for(int i=2;i<maxn;i++)if(!mn[i])
	{
		for(int j=i;j<maxn;j+=i)if(!mn[j])mn[j]=i;
		p[tot++]=i;
	}
	
	vector<int> fc;
	for(int i=1;i<maxn;i++)
	{
		eq[i]=getf(i,dv[i],fc);
		if(eq[i]==i)
		{
			cnt++;
			id[i]=cnt;
			do_dp(dist[cnt],fc);
		}
	}
	
	int tc,a,b;get1(tc);
	while(tc--)
	{
		get2(a,b);a=id[eq[a]];b=id[eq[b]];
		int ans=inf;
		for(int i=1;i<=magic;i++)ans=min(ans,dist[a][i]+dist[b][i]);
		printendl(ans);
	}
	return 0;
}