#include <stdio.h>

void solve(){
	int n;
	scanf("%d",&n);
	if(n==1){
		puts("a");
	}else{
		if(n&1){
			int len1 = n/2;
			int len2 = n/2-1;
			for(int i=0;i<len1;i++) putchar('a');
			putchar('b'),putchar('c');
			for(int i=0;i<len2;i++) putchar('a');
			putchar('\n');
		}else{
			int len1 = n/2;
			int len2 = n/2-1;
			for(int i=0;i<len1;i++) putchar('a');
			putchar('b');
			for(int i=0;i<len2;i++) putchar('a');
			putchar('\n');
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}