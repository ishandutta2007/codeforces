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

const int maxm=5111;

bool pr[maxm];
int n,b[maxm],ptot;
int cnt[maxm][maxm],lcp[maxm],dist[maxm][maxm],mn[maxm][maxm];

int getlcp(int x,int y)
{
	assert(x!=y);
	int lb=1,rb=ptot+1,mid;
	while(lb<rb-1)
	{
		mid=(lb+rb)>>1;
		if(cnt[x][mid]!=cnt[y][mid])lb=mid;
		else rb=mid;
	}
	return min(cnt[x][lb],cnt[y][lb]);
}

int main()
{
	for(int i=2;i<maxm;i++)pr[i]=1;
	for(int i=2;i<maxm;i++)if(pr[i])
	{
		ptot++;
		for(int j=i;j<maxm;j+=i)
		{
			pr[j]=0;
			int tmp=j;
			while(tmp%i==0)
			{
				cnt[j][ptot]++;
				tmp/=i;
			}
		}
	}
	for(int i=2;i<maxm-1;i++)
	{
		for(int j=1;j<=ptot;j++)cnt[i+1][j]+=cnt[i][j];
		for(int j=ptot;j>=1;j--)cnt[i][j]+=cnt[i][j+1];
	}
	for(int i=2;i<maxm;i++)lcp[i-1]=getlcp(i-1,i);
	for(int i=1;i<maxm;i++)
	{
		mn[i][i]=inf;
		for(int j=i+1;j<maxm;j++)
		{
			mn[i][j]=min(mn[i][j-1],lcp[j-1]);
			mn[j][i]=mn[i][j];
		}
	}
	for(int i=1;i<maxm;i++)for(int j=1;j<maxm;j++)if(i!=j)dist[i][j]=cnt[i][1]+cnt[j][1]-mn[i][j]*2;
	get1(n);
	for(int i=1;i<=n;i++)
	{
		int x;get1(x);if(!x)x++;
		b[x]++;
	}
	
	LL ans=Linf;
	for(int i=1;i<maxm;i++)if(b[i])
	{
		LL sum=0;
		for(int j=1;j<maxm;j++)if(b[j])
			sum+=(LL)dist[i][j]*b[j];
		ans=min(ans,sum);
	}
	for(int i=1;i<maxm-1;i++)
	{
		LL sum=0;
		for(int j=1;j<maxm;j++)if(b[j])
		{
			int d;
			if(mn[i][j]>=lcp[i])d=cnt[j][1]-lcp[i];
			else d=cnt[j][1]+lcp[i]-mn[i][j]*2;
			sum+=(LL)d*b[j];
		}
		ans=min(ans,sum);
	}
	printendl(ans);
	
	return 0;
}