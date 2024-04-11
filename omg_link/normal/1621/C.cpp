#include <stdio.h>
#define MN 10000

int query(int i){
	printf("? %d\n",i);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}

int p[MN+5];

void solve(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		p[i] = -1;
	for(int i=1;i<=n;i++){
		if(p[i]!=-1) continue;
		int src = query(i);
		int lst = src;
		while(true){
			int cur = query(i);
			p[lst] = cur;
			lst = cur;
			if(cur==src) break;
		}
	}
	printf("! ");
	for(int i=1;i<=n;i++)
		printf("%d%c",p[i]," \n"[i==n]);
	fflush(stdout);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}