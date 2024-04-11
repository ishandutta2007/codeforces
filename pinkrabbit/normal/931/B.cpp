#include<bits/stdc++.h>
int n,a,b;
int main(){
	scanf("%d%d%d",&n,&a,&b);
	a+=n-1,b+=n-1;
	int cnt=0;
	while(a!=b) a/=2, b/=2, ++cnt;
	if((1<<cnt)==n) puts("Final!");
	else printf("%d",cnt);
	return 0;
}