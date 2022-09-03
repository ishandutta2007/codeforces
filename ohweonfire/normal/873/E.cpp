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
const LL Linf=1ll<<62;
const double pi=acos(-1.0);

pii a[3333];
int n,bp,bq,br,best[3],cur[3],mx[3333][3333],v[3333],ans[3333];
int main()
{
	get1(n);
	for(int i=1;i<=n;i++){get1(a[i].ff);a[i].ss=i;}
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++)v[i]=a[i].ff-a[i+1].ff;
//	for(int i=1;i<=n;i++)printf("%d ",v[i]);puts("");
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)
	{
		mx[i][j]=j;
		if(i<j&&v[j]<v[mx[i][j-1]])mx[i][j]=mx[i][j-1];
	}
	memset(best,-1,sizeof(best));
	for(int p=1;p<=n;p++)for(int q=1;q<=n;q++)
	{
		if(p*2<q||q*2<p)continue;
//		printf("p=%d q=%d\n",p,q);
		int lb=max(p,q)+1>>1,ub=min(p,q)<<1;
		lb+=p+q;ub+=p+q;ub=min(ub,n);lb=max(lb,p+q+1);
		if(lb>ub)continue;
		int r=mx[lb][ub];
		cur[0]=a[p].ff-a[p+1].ff;cur[1]=a[p+q].ff-a[p+q+1].ff;cur[2]=a[r].ff-a[r+1].ff;
		bool ok=1;for(int i=0;i<3;i++)if(cur[i]!=best[i]){ok=(cur[i]>best[i]);break;}
		if(ok)
		{
			bp=p;bq=p+q;br=r;
			memcpy(best,cur,sizeof(cur));
		}
	}
	memset(ans,-1,sizeof(ans));
	for(int i=1;i<=bp;i++)ans[a[i].ss]=1;
	for(int i=bp+1;i<=bq;i++)ans[a[i].ss]=2;
	for(int i=bq+1;i<=br;i++)ans[a[i].ss]=3;
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}