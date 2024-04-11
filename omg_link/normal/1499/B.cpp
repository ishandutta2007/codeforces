#include <stdio.h>
#include <string.h>
#define MN 100

int n;
char s[MN+5];

bool check(int p){
	int lst = -2;
	for(int i=1;i<=n;i++){
		if((i<=p&&s[i]=='1')||(i>p&&s[i]=='0')){
			if(i-lst==1) return false;
			lst = i;
		}
	}
	return true;
}

void solve(){
	scanf("%s",&s[1]);
	n = strlen(&s[1]);
	for(int i=0;i<=n;i++){
		if(check(i)){
			puts("YES");
			return;
		}
	}
	puts("NO");
	return;
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}