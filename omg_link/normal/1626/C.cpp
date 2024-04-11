#include <stdio.h>
#include <algorithm>
#define MN 100

using std::min,std::max;

using ll = long long;

int n;
int k[MN+5],h[MN+5],d[MN+5];

ll sum(int l,int r){
	return (ll)(l+r)*(r-l+1)/2;
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&k[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	d[n] = h[n];
	for(int i=n-1;i>=1;i--){
		d[i] = max(h[i],d[i+1]-(k[i+1]-k[i]));
	}
	ll ans = 0;
	for(int i=1;i<=n;i++){
		if(d[i]>k[i]-k[i-1]){
			d[i] = d[i-1]+(k[i]-k[i-1]);
			ans += sum(d[i-1]+1,d[i]);
		}else{
			ans += sum(1,d[i]);
		}
	}
	printf("%lld\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}