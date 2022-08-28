#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int w1,h1,w2,h2,ans=0;
int main()
{
	scanf("%d%d%d%d",&w1,&h1,&w2,&h2);
	ans=(w1+h1+h2)*2+4;
	printf("%d",ans);
	return 0;
}