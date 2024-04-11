#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,cnt,vis[1005];
int main()
{
	scanf("%d",&n);
	while(n)
	{
		if(n<=1000&&vis[n]) break;
		cnt++;
		if(n<=1000) vis[n]=1;
		n++;
		while(n&&n%10==0) n/=10;
	}
	printf("%d",cnt);
	return 0;
}