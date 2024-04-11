#include <stdio.h>
#include <algorithm>
#define MN 100000
typedef long long LL;

int n;
LL c[MN+5];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	LL mh = c[1];
	LL mv = c[2];
	LL sh = c[1];
	LL sv = c[2];
	LL ch = 1;
	LL cv = 1;
	LL ans = mh*n+mv*n;
	for(int i=3;i<=n;i++){
		if(i&1){
			mh = std::min(mh,c[i]);
			sh += c[i];
			ch++;
		}else{
			mv = std::min(mv,c[i]);
			sv += c[i];
			cv++;
		}
		ans = std::min(ans,mh*(n-ch)+sh+mv*(n-cv)+sv);
	}
	printf("%lld\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}