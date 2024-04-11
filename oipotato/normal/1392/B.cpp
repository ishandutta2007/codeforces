#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int inf=(int)1e9+10;
int a[200010];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int n;
		long long k;
		scanf("%d%lld",&n,&k);
		k&=1;
		int mx=-inf,mi=inf;
		rep(i,n)scanf("%d",&a[i]),mx=max(mx,a[i]),mi=min(mi,a[i]);
		if(k)rep(i,n)printf("%d%c",mx-a[i]," \n"[i==n]);
		else rep(i,n)printf("%d%c",a[i]-mi," \n"[i==n]);

	}
    return 0;
}