#include <stdio.h>
#define MN 100

int n,k,h[MN+5];

void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	h[n+1] = 0;
	int lstPos=0;
	while(k--){
		for(int i=1;i<=n+1;i++){
			if(i==n+1){
				lstPos = -1;
				break;
			}
			if(h[i]<h[i+1]){
				h[i]++;
				lstPos = i;
				break;
			}
		}
		if(lstPos==-1) break;
	}
	printf("%d\n",lstPos);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}