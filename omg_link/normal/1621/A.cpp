#include <stdio.h>
#define MN 40

char s[MN+5][MN+5];

void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	if(2*k-1>n){
		puts("-1");
	}else{
		for(int i=1;i<=n;i++){	
			for(int j=1;j<=n;j++)
				s[i][j] = '.';
			s[i][n+1] = '\0';
		}
		for(int i=1;i<=k;i++)
			s[2*i-1][2*i-1] = 'R';
		for(int i=1;i<=n;i++)
			puts(&s[i][1]);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}