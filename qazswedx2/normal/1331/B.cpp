#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,prime[15]={0,2,3,5,7,11,13,17,19,23,29},pt=8;
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		if(n%i==0)
		{
			printf("%d%d",i,n/i);
			return 0;
		}
	return 0;
}