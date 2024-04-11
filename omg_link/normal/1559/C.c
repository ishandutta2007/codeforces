#include <stdio.h>
#define MN 10000

int n,a[MN+5];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(a[1]==1){
		printf("%d ",n+1);
		for(int i=1;i<=n;i++)
			printf("%d%c",i," \n"[i==n]);
	}else{
		int pos = n;
		for(int i=1;i<n;i++)
			if(a[i]!=a[i+1]){
				pos = i;
				break;
			}
		if(pos==n){
			for(int i=1;i<=n;i++)
				printf("%d ",i);
			printf("%d\n",n+1);
		}else{
			for(int i=1;i<=pos;i++)
				printf("%d ",i);
			printf("%d ",n+1);
			for(int i=pos+1;i<=n;i++)
				printf("%d%c",i," \n"[i==n]);
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}