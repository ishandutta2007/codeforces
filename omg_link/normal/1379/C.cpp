#include <stdio.h>
#include <algorithm>
#define MM 100000
typedef long long LL;

int n,m,a[MM+5];
struct flower{
	int a,b;
}f[MM+5];
LL ans,tans;

void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&f[i].a,&f[i].b);
		a[i] = f[i].a;
	}
	std::sort(a+1,a+1+m,std::greater<int>());
	std::sort(f+1,f+1+m,[](flower a,flower b)->bool{return a.b>b.b;});
	ans = 0;
	tans = 0;
	for(int i=1,j=0;i<=m;i++){
		while(j<m && a[j+1]>=f[i].b){
			j++;
			tans += a[j];
		}
		if(f[i].a >= f[i].b){
			if(j>n) continue;
			ans = std::max(ans,tans+1ll*(n-j)*f[i].b);
		}else{
			if(j+1>n) continue;
			ans = std::max(ans,tans+f[i].a+1ll*(n-j-1)*f[i].b);
		}
	}
	tans = 0;
	for(int i=1;i<=n&&i<=m;i++){
		tans += a[i];
	}
	ans = std::max(ans,tans);
	printf("%lld\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve(); 
}