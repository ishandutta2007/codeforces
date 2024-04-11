#include <stdio.h>
#include <algorithm>

using std::swap;

using ll = long long;

void solve(){
	ll a,b,x;
	scanf("%lld%lld%lld",&a,&b,&x);
	
	if(a<b) swap(a,b);
	while(b>0){
		ll l = (a%b)/b;
		ll r = a/b;
		if(x%b==a%b){
			ll v = (x-(a%b))/b;
			if(l<=v&&v<=r){
				puts("YES");
				return;
			}
		}
		a %= b;
		swap(a,b);
	}
	
	puts("NO");
	return;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}