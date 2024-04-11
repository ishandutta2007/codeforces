#include <stdio.h>
#include <string.h>
#define MN 100000

int n;
char s[MN+5];

void solve(){
	scanf("%s",&s[1]);
	n = strlen(&s[1]);
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(i>=2){
			if(s[i]==s[i-1]){
				s[i] = 0;
				cnt++;
				continue;
			}
		}
		if(i>=3){
			if(s[i]==s[i-2]){
				s[i] = 0;
				cnt++;
				continue;
			}
		}
	}
	printf("%d\n",cnt);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}