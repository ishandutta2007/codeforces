#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn=300000;
typedef long long ll;
int n;
ll a[Maxn+5],b[Maxn+5],c[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	ll sum;
	ll ans;
	while(T--){
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld",&a[i],&b[i]);
			ans+=a[i];
			c[i]=max(0ll,a[i]-b[i-1]);
		}
		c[1]=max(0ll,a[1]-b[n]);
		sum=0;
		for(int i=1;i<=n;i++){
			sum+=c[i];
		}
		for(int i=1;i<=n;i++){
			ans=min(ans,sum-c[i]+a[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}