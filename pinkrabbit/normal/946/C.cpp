#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)

int n;
char str[100001];

int main(){
	scanf("%s",str+1);
	n=strlen(str+1);
	char want='a';
	F(i,1,n){
		if(str[i]<=want) str[i]=want, ++want;
		if(want=='z'+1) break;
	}
	if(want<='z') {puts("-1"); return 0;}
	printf("%s",str+1);
	return 0;
}