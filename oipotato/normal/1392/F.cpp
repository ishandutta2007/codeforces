#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
long long a[1000010],b[1000010],sum;
int main()
{
	int n;
	scanf("%d",&n);
	rep(i,n)scanf("%lld",&a[i]),sum+=a[i]-(i-1);
	rep(i,n)b[i]=i-1+sum/n;
	sum%=n;
	rep(i,sum)b[i]++;
	rep(i,n)printf("%lld%c",b[i]," \n"[i==n]);
    return 0;
}