#include <stdio.h>
#define MN 200000

char s[MN+5];

void solve(){
	scanf("%s",&s[1]);
	int pos = -1;
	for(int i=2;s[i];i++){
		if((s[i]-'0')+(s[i-1]-'0')>=10) pos = i;
	}
	if(pos!=-1){
		s[pos] = (s[pos]-'0')+(s[pos-1]-'0')-10+'0';
		s[pos-1] = '1';
		puts(&s[1]);
	}else{
		s[2] = (s[1]-'0')+(s[2]-'0')+'0';
		puts(&s[2]);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}