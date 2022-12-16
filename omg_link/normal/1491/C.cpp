#include <stdio.h>
#include <algorithm>
#define MN 5000

int n,a[MN+5],np[MN+5];

int gnp(int u){
	return np[u]==u?u:np[u]=gnp(np[u]);
}

void simu(int p){
	while(p<=n){
		p = gnp(p);
		if(p>n) break;
		int t = p;
		p += a[t];
		if(a[t]!=1){
			a[t]--;
			if(a[t]==1)
				np[t] = t+1;
		}
	}
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[n+1] = 0;
	for(int i=1;i<=n+1;i++){
		if(a[i]==1){
			np[i] = i+1;
		}else{
			np[i] = i;
		}
	}
	long long ans = 0;
	for(int i=1;i<=n;i++){
		if(a[i]>std::max(n-i,1)){
			ans += a[i]-std::max(n-i,1);
			a[i] = n-i;
			if(a[i]==1)
				np[i] = i+1;
		}
		while(a[i]>1){
			simu(i);
			ans++;
		}
	}
	printf("%lld\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}