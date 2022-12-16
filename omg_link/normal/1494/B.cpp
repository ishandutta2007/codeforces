#include <stdio.h>

void solve(){
	int n,U,D,R,L;
	scanf("%d%d%d%d%d",&n,&U,&R,&D,&L);
	for(int S=0;S<16;S++){
		int u=U,d=D,r=R,l=L;
		if(S&1) u--,l--;
		if(S&2) d--,l--;
		if(S&4) d--,r--;
		if(S&8) u--,r--;
		if(u<0||u>n-2) continue;
		if(d<0||d>n-2) continue;
		if(l<0||l>n-2) continue;
		if(r<0||r>n-2) continue;
		puts("YES");
		return;
	}
	puts("NO");
	return;
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}