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

const int maxn=111;

bool dp[maxn][maxn*maxn/2];
int pre[maxn][maxn*maxn/2],tp[maxn][maxn*maxn/2],q,n,k;

vector<int> all[maxn],ind[maxn];

vector<int> merge(const vector<int>&a,const vector<int>&b)
{
	vector<int> ret;
	int cur=b[0];
	for(auto v:a)ret.pb(v+cur-1);
	if((b[1]>b[0])==(ret[0]<ret[(int)ret.size()-1]))reverse(ret.begin(),ret.end());
	for(auto v:b)if(v<cur)ret.pb(v);else if(v>cur)ret.pb(v+(int)a.size()-1);
	return ret;
}

vector<int> calc(int n,int k)
{
	if(k==n*(n+1)/2)return all[n];
	else if(k==n+1)return ind[n];
	if(tp[n][k]==0)return merge(calc(n-pre[n][k]+1,k-pre[n][k]),ind[pre[n][k]]);
	else return merge(calc(n-pre[n][k]+1,k-pre[n][k]*(pre[n][k]+1)/2+1),all[pre[n][k]]);
}

void solve()
{
	get2(n,k);
	if(n==1)
	{
		puts("YES");
		puts("1");
		return;
	}
	if(dp[n][k])
	{
		puts("YES");
		vector<int> ans=calc(n,k);
		for(auto v:ans)printf("%d ",v);puts("");
	}
	else puts("NO");
}

int main()
{
	for(int i=2;i<=100;i++)
	{
		if(i>3)dp[i][i+1]=1;
		dp[i][i*(i+1)/2]=1;
		for(int j=i+1;j<=i*(i+1)/2;j++)if(dp[i][j])
		{
			for(int k=2;i+k-1<=100;k++)
			{
				dp[i+k-1][j+k*(k+1)/2-1]=1;
				pre[i+k-1][j+k*(k+1)/2-1]=k;
				tp[i+k-1][j+k*(k+1)/2-1]=1;
				if(k>3)
				{
					dp[i+k-1][j+k]=1;
					pre[i+k-1][j+k]=k;
					tp[i+k-1][j+k]=0;
				}
			}
		}
	}
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=i;j++)all[i].pb(j);
		if(i<=3)continue;
		if(i%2==0)
		{
			for(int j=2;j<=i;j+=2)ind[i].pb(j);
			for(int j=1;j<=i;j+=2)ind[i].pb(j);
		}
		else
		{
			ind[i]=ind[i-1];
			ind[i].pop_back();
			ind[i].pb(i);
			ind[i].pb(i-2);
		}
	}
	get1(q);
	while(q--)solve();
	return 0;
}