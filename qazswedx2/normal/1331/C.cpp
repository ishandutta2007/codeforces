#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,ans;
int main()
{
	scanf("%d",&n);
	if(n&(1<<1)) ans|=(1<<1);
	if(n&(1<<0)) ans|=(1<<4);
	if(n&(1<<2)) ans|=(1<<3);
	if(n&(1<<5)) ans|=(1<<5);
	if(n&(1<<3)) ans|=(1<<2);
	if(n&(1<<4)) ans|=(1<<0);
	printf("%d",ans);
	return 0;
}