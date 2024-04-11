#include <stdio.h>
#define MN 50

char s[MN+5];

void solve(){
	scanf("%s",&s[1]);
	for(int a=-1;a<=1;a+=2){
		for(int b=-1;b<=1;b+=2){
			for(int c=-1;c<=1;c+=2){
				int v = 0;
				bool flag = false;
				for(int i=1;s[i];i++){
					if(s[i]=='A'){
						v += a;
					}
					if(s[i]=='B'){
						v += b;
					}
					if(s[i]=='C'){
						v += c;
					}
					if(v<0){
						flag = true;
						break;
					}
				}
				if(flag) continue;
				if(v!=0) continue;
				puts("YES");
				return;
			}
		}
	}
	puts("NO");
	return;
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}