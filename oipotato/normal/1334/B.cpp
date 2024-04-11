#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
int a[100010],x;
int main()
{
	int T;scanf("%d",&T);
	for(;T--;)
	{
		int n;scanf("%d%d",&n,&x);
		rep(i,n)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		reverse(a+1,a+n+1);
		long long sum=0;
		rep(i,n)
		{
			sum+=a[i];
			if(sum<1ll*x*i){printf("%d\n",i-1);break;}
			if(i==n)printf("%d\n",n);
		}
	}
	return 0;
}