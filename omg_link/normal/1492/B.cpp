#include <stdio.h>
#include <algorithm>
#define MN 100000

int n,a[MN+5],p[MN+5];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		p[a[i]] = i;
	}
	for(int i=n,lst=n+1;i>=1;i--){
		for(int j=p[i];j<lst;j++)
			printf("%d ",a[j]);
		lst = std::min(lst,p[i]);
	}
	puts("");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}