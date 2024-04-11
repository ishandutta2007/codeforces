// This amazing code is by Eric Sunli Chen.
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template<typename T> void get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'; t=getchar());
	if(t=='-')neg=true,t=getchar();
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;
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
#define get2(a,b) get1(a),get1(b)
#define get3(a,b,c) get1(a),get2(b,c)
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

int n,m,one[1<<20],cnt[25],c[25][25];
char s[55][25];
LL msk[25],all[1<<20];
double calc(int x)
{
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<m;i++)
	{
		msk[i]=0;
		for(int j=0;j<n;j++)if(j!=x&&s[j][i]==s[x][i])
			msk[i]|=1ll<<j;
	}
	all[0]=(1ll<<n)-1;
	for(int i=0;i<(1<<m);i++)
	{
		for(int j=0;j<m;j++)
		{
			if((i>>j)&1)
			{
				all[i]=all[i^(1<<j)]&msk[j];
				break;
			}
		}
		if(all[i])cnt[one[i]]++;
	}
	double ret=0.0,sum=0.0;
	for(int i=0;i<m;i++)
	{
		cnt[i]=cnt[i]*(m-i)-cnt[i+1]*(i+1);
		ret+=1.0*(i+1)*cnt[i]/c[m][i]/(m-i);
		sum+=1.0*cnt[i]/c[m][i]/(m-i);
	}
	return ret;
}
int main()
{
	for(int i=0;i<25;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
	for(int i=1;i<(1<<20);i++)one[i]=(one[i>>1]+(i&1));
	get1(n);
	if(n==1)
	{
		printf("0.00000000000\n");
		return 0;
	}
	for(int i=0;i<n;i++)scanf("%s",s[i]);
	m=strlen(s[0]);
	double ans=0.0;
	for(int i=0;i<n;i++)
		ans+=calc(i);
	printf("%.10lf\n",ans/n);
	return 0;
}