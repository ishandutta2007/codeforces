#include <stdio.h>
#include <vector>
#define MA 20000000
typedef long long LL;

bool np[MA+5];
int cnt[MA+5];
std::vector<int> ps;

void init(){
	for(int i=2;i<=MA;i++){
		if(!np[i]){
			ps.push_back(i);
			cnt[i] = 1;
		}
		for(int p:ps){
			if(p*i>MA) break;
			np[p*i] = true;
			cnt[p*i] = cnt[i];
			if(i%p==0) break;
			cnt[p*i]++;
		}
	}
}

LL calc(LL n,LL c){
	if(n%c) return 0;
	n /= c;
	return 1<<cnt[n];
}

void solve(){
	LL c,d,x;
	scanf("%lld%lld%lld",&c,&d,&x);
	LL ans = 0;
	for(int i=1;i*i<=x;i++){
		if(x%i==0){
			ans += calc(i+d,c);
			if(i*i!=x) ans += calc(x/i+d,c);
		}
	}
	printf("%lld\n",ans);
}

int main(){
	init();
	int T; scanf("%d",&T);
	while(T--) solve();
}