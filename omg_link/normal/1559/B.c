#include <stdio.h>
#define MN 100

int n;
char s[MN+5];

void solve(){
	scanf("%d%s",&n,&s[1]);
	int bsc = -1;
	for(int i=1;i<=n;i++)
		if(s[i]!='?') bsc = i;
	if(bsc==-1){
		s[1] = 'R';
		bsc = 1;
	}
	for(int i=bsc-1;i>=1;i--){
		if(s[i]=='?'){
			if(s[i+1]=='R') s[i] = 'B';
			else s[i] = 'R';
		}
	}
	for(int i=bsc+1;i<=n;i++){
		if(s[i]=='?'){
			if(s[i-1]=='R') s[i] = 'B';
			else s[i] = 'R';
		}
	}
	puts(&s[1]);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}