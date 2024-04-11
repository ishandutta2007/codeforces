#include <stdio.h>
#include <algorithm>
#define MN 100

int n,d,a[MN+5];

void solve(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	std::sort(a+1,a+1+n);
	if(a[n]<=d){
		puts("YES");
	}else if(a[1]+a[2]<=d){
		puts("YES");
	}else{
		puts("NO");
	}
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}