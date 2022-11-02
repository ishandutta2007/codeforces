#include <iostream>
#include <cstdio>
#include <cstring>

int main(){
	int n;scanf("%d",&n);
	if(n & 1 || n == 2) printf("%s","NO");
	else printf("%s","YES");
	return 0;
}