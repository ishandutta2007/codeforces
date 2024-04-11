#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)

#define FILE_IN "tree.inp"
#define FILE_OUT "tree.out"
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
#define pow2(x) (ll(1)<<x)
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
const int N=2000+10;
int now[N],sum[N],p[N];
bool use[N];
void add(int *a,int *b)
{
	int c=0,x;
	For(i,0,2000)x=a[i]+b[i]+c,b[i]=x%10,c=x/10;
}
void mul(int *a)
{
	int c=0,x;
	For(i,0,2000)x=a[i]*2+c,a[i]=x%10,c=x/10;
}
int n,a[5010],op[5010];
char s[10];
int main()
{
	memset(p,-1,sizeof p);
	scanf("%d",&n);
	For(i,0,n-1)
	{
		scanf("%s%d",s,&a[i]);
		if(s[0]=='w')op[i]=0;else op[i]=1,p[a[i]]=i;
	}
	Rep(i,2000,0)if(p[i]!=-1&&op[p[i]]!=-1)
	{
		int k=-1;
		Rep(j,p[i]-1,0)
		{
			if(op[j]==-1)break;
			if(a[j]==i){k=j;break;}
		}
		if(k!=-1)
		{
			use[i]=1;
			For(j,k,p[i])op[j]=-1;
		}
	}
	now[0]=1;
	For(i,0,2000)
	{
		if(use[i])add(now,sum);
		mul(now);
	}
	int k=2000;
	for(;k>=0&&sum[k]==0;k--);
	if(k==-1)puts("0");else
	{
		Rep(i,k,0)printf("%d",sum[i]);
		puts("");
	}
}