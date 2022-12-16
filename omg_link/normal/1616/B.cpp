#include <stdio.h>
#define MN 100000

int n;
char s[MN+5];

void solve(){
	scanf("%d%s",&n,&s[1]);
	if(n==1){
		s[++n] = s[1];
	}
	if(s[1]==s[2]){
		s[3] = '\0';
		puts(&s[1]);
		return;
	}
	s[n+1] = 0x7f;
	for(int i=2;i<=n+1;i++){
		if(s[i]>s[i-1]){
			for(int j=1;j<=i-1;j++)
				putchar(s[j]);
			for(int j=i-1;j>=1;j--)
				putchar(s[j]);
			putchar('\n');
			return;
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}