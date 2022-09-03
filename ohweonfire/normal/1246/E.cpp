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
 
#define getcode(i,j) (((i)>>(j))&1)
int n,k,a[20],sum[1<<16];
 
bitset<2111> dp[1<<16];
int b[20];
 
void dfs(int msk,int t,int layer)
{
	if(msk==0)return;
	for(int i=0;i<n;i++)if(getcode(msk,i)&&t>=a[i]&&dp[msk^(1<<i)].test(t-a[i]))
	{
		b[i]=layer;
		dfs(msk^(1<<i),t-a[i],layer);
		return;
	}
	dfs(msk,t*k,layer+1);
}
 
int main()
{
	get2(n,k);
	for(int i=0;i<n;i++)get1(a[i]);
	for(int i=0;i<(1<<n);i++)for(int j=0;j<n;j++)if(getcode(i,j))sum[i]+=a[j];
	
	dp[0].set(0);
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)if(getcode(i,j))dp[i]|=(dp[i^(1<<j)]<<a[j]);
		for(int j=sum[i]/k*k;j>=0;j-=k)if(dp[i].test(j))dp[i].set(j/k);
	}
	if(dp[(1<<n)-1].test(1))
	{
		puts("YES");
		dfs((1<<n)-1,1,0);
		priority_queue<pii> pq;
		for(int i=0;i<n;i++)pq.push(mp(b[i],a[i]));
		while(pq.size()>1)
		{
			pii t1=pq.top();pq.pop();pii t2=pq.top();pq.pop();
			printf("%d %d\n",t1.ss,t2.ss);
			t1.ss+=t2.ss;
			while(t1.ss%k==0)
			{
				t1.ss/=k;
				t1.ff--;
			}
			pq.push(t1);
		}
	}
	else puts("NO");
	return 0;
}