#include <stdio.h>
#include <algorithm>
#define MN 100000

int n,x,a[MN+5];

int upper_div(int a,int b){
	return a/b+(a%b>0);
}

void solve(){
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	std::sort(a+1,a+1+n);
	
	int ans=0, count=0;
	for(int i=n;i>=1;i--){
		count++;
		if(1ll*count*a[i]>=x){
			count -= upper_div(x,a[i]);
			ans++;
		}
	}
	printf("%d\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}