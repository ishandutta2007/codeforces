#include <stdio.h>
#define MN 52

char s[MN+5];

void solve(){
	scanf("%s",&s[1]);
	int cnt[26] = {0};
	for(int i=1;s[i];i++){
		cnt[s[i]-'a']++;
	}
	for(int i=0;i<26;i++){
		if(cnt[i]==2) putchar(i+'a');
	}
	for(int i=0;i<26;i++){
		if(cnt[i]==1) putchar(i+'a');
	}
	for(int i=0;i<26;i++){
		if(cnt[i]==2) putchar(i+'a');
	}
	puts("");
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}