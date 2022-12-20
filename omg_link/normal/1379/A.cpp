#include <stdio.h>
#include <string.h>
#define ML 50

const char *str="abacaba";
char s[ML+5],t[ML+5];

bool solve(){
	scanf("%*d%s",&s[1]);
	int len=strlen(&s[1]);
	for(int i=1;i+6<=len;i++){
		memcpy(t,s,sizeof(s));
		for(int j=0;j<7;j++){
			if(t[i+j]=='?') t[i+j]=str[j];
			if(t[i+j]!=str[j]) break;
		}
		for(int j=1;j<=len;j++){
			if(t[j]=='?') t[j]='d';
		}
		int cnt=0;
		for(int j=1;j+6<=len;j++){
			cnt++;
			for(int k=0;k<7;k++){
				if(t[j+k]!=str[k]){
					cnt--;
					break;
				}
			}
		}
		if(cnt==1) return true;
	}
	return false;
}

int main(){
	int T; scanf("%d",&T);
	while(T--){
		if(solve()){
			puts("Yes");
			printf("%s\n",&t[1]);
		}else{
			puts("No");
		}
	}
}