#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
using namespace std;
const int N=2e5+9;
int a[N];
ll ans[N],sum[N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,n)scanf("%d",&a[i]);
	sort(a,a+n);
	rep(i,0,n){
		sum[i%m]+=a[i];
		if(i)ans[i]+=ans[i-1]+sum[i%m];
		else ans[0]=sum[0];
	}
	rep(i,0,n)printf("%lld ",ans[i]);
}