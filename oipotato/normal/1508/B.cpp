#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
int a[100010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;
		long long k;
		scanf("%d%lld",&n,&k);
		if(n<=60&&(1ll<<(n-1))<k){puts("-1");continue;}
		int now=1;
		rep(i,n)a[i]=i;
		for(;now<=n;now++)
		{
			int last=now;
			for(;now<=n&&max(0,(n-now-1))<=60&&(1ll<<max(0,(n-now-1)))<k;k-=1ll<<max(0,(n-now-1)),now++);
			reverse(a+last,a+now+1);
		}
		rep(i,n)printf("%d%c",a[i]," \n"[i==n]);
	}
	return 0;
}