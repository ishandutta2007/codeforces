#include <stdio.h>
#include <algorithm>
int a,b,c;
int main(){
	scanf("%d%d%d",&a,&b,&c);
	a=std::min(a,b-1);
	b=std::min(b,a+1);
	b=std::min(b,c-1);
	c=std::min(c,b+1);
	a=std::min(a,b-1);
	b=std::min(b,a+1);
	b=std::min(b,c-1);
	c=std::min(c,b+1);
	a=std::min(a,b-1);
	b=std::min(b,a+1);
	b=std::min(b,c-1);
	c=std::min(c,b+1);
	printf("%d\n",a+b+c);
}