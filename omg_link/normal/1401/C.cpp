#include <stdio.h>
#include <algorithm>
#define MN 100000

int n,a[MN+5],b[MN+5];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i] = a[i];
	}
	std::sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		if(a[i] != b[i]){
			if(a[i]%b[1]){
				puts("NO");
				return;
			}
		}
	}
	puts("YES");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}