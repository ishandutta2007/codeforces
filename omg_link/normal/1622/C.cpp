#include <stdio.h>
#include <algorithm>
#define MN 200000

using ll = long long;

using std::max,std::min;
using std::sort;

int n,a[MN+5];
ll k,sum;

ll dndiv(ll x,ll y){
	if(x>=0) return x/y; 
	else return x/y-(x%y!=0);
}

ll calc(int cnt){
	//(cnt+1)*val<=k-sum
	ll minVal = min(dndiv(k-sum,cnt+1),(ll)a[1]);
	return a[1]-minVal+cnt;
}

void solve(){
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	ll ans = 1e18;
	sum = -a[1];
	for(int i=1;i<=n;i++){
		sum += a[i];
		ans = min(ans,calc(n-i));
	}
	printf("%lld\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}