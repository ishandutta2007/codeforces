#include <stdio.h>
#include <string.h>
#define MN 100000

char s[MN+5],t[MN+5];
int n,x;

void m0(int x){
	if(x<1||x>n) return;
	t[x] = '0';
}

bool i1(int x){
	if(x<1||x>n) return false;
	return t[x]=='1';
}

char check(int p){
	if(i1(p-x)||i1(p+x)) return '1';
	return '0';
}

void solve(){
	scanf("%s%d",&s[1],&x);
	n = strlen(&s[1]);
	for(int i=1;i<=n;i++) t[i] ='1';
	for(int i=1;i<=n;i++)
		if(s[i]=='0')
			m0(i-x),m0(i+x);
	for(int i=1;i<=n;i++)
		if(check(i)!=s[i]){
			puts("-1");
			return;
		}
	for(int i=1;i<=n;i++)
		putchar(t[i]);
	putchar('\n');
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}