#include<cstdio>
int a,b;
int main(){
	scanf("%d%d",&a,&b);
	if(a==0&&b==0)puts("NO");
	else if(a-1==b||a==b||a==b-1)puts("YES");
	else puts("NO");
	return 0;
}