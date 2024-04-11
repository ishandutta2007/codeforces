#include <stdio.h>
#include <string.h>
#define MN 100

int n,k,a[MN+5];
bool e[MN+5];

void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(k==1){
		for(int i=1;i<=n;i++)
			if(a[i]!=a[1]){
				puts("-1");
				return;
			}
		puts("1");
	}else{
		memset(e,0,sizeof(e));
		int sz = 0;
		for(int i=1;i<=n;i++){
			if(!e[a[i]]){
				e[a[i]] = true;
				sz++; 
			}
		}
		if(sz<=k)
		    puts("1");
		else
		    printf("%d\n",(sz-1+k-2)/(k-1));
	}
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}