#include <stdio.h>
#include <string.h>
#define ML 400

int lens,lent;
char s[ML+5],t[ML+5];

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}

int lcm(int x,int y){
	return x*y/gcd(x,y);
}

void solve(){
	scanf("%s%s",&s[0],&t[0]);
	lens = strlen(s);
	lent = strlen(t);
	int L = lcm(lens,lent);
	for(int i=0;i<L;i++){
		if(s[i%lens]!=t[i%lent]){
			puts("-1");
			return;
		}
	}
	for(int i=0;i<L;i++)
		putchar(s[i%lens]);
	puts("");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}