#include <stdio.h>
#define MN 1000000

int n;
char l[MN+5],r[MN+5];

bool g2(){
	for(int i=n-1;i>=0;i--)
		if(l[i]=='1'){
			l[i] = '0';
		}else{
			l[i] = '1';
			break;
		}
	if(l[0]=='1') return false;
	for(int i=1;i<=n;i++)
		if(l[i]!=r[i])
			return r[i]>l[i];
	return true;
}

int main(){
	scanf("%d",&n);
	scanf("%s%s",&l[1],&r[1]);
	if(l[1]!=r[1]){
		for(int i=1;i<=n;i++)
			putchar('1');
		putchar('\n');
		return 0;
	}
	if(r[n]=='1'){
		printf("%s\n",&r[1]);
		return 0;
	}
	if(n==1){
		puts("0");
		return 0;
	}
	if(g2()){
		r[n] = '1';
		printf("%s\n",&r[1]);
		return 0;
	}else{
		printf("%s\n",&r[1]);
		return 0;
	}
}