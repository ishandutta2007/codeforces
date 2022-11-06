#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll ans=9e18;
int a[100],b[100],n,m;
ll work(int x){
	ll ans=-9e18;
	for(int i=1;i<=n;++i) if(i!=x)
		for(int j=1;j<=m;++j) ans=max(ans,1ll*a[i]*b[j]);
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int j=1;j<=m;++j) scanf("%d",&b[j]);
	for(int i=1;i<=n;++i) ans=min(ans,work(i));
	printf("%lld",ans);
}