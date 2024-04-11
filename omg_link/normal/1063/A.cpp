#include <stdio.h>
#include <algorithm>
#define MN 100000
int n; char s[MN+5];
int main(){
	scanf("%d%s",&n,&s[1]);
	std::sort(s+1,s+1+n);
	printf("%s",&s[1]);
}
//Why I get an unknown error?