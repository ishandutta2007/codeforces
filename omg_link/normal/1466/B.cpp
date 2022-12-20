#include <stdio.h>
#define MN 100000

int n,a[MN+5];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans = 0;
	for(int i=1,lst=-1;i<=n;i++){
		if(lst<a[i]){
			lst = a[i];
			ans++;
		}else if(lst==a[i]){
			lst = a[i]+1;
			ans++;
		}
	}
	printf("%d\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}