#include<bits/stdc++.h>
int n;
int main(){
	scanf("%d",&n);
	printf("%d",32-__builtin_clz(n));
	return 0;
}