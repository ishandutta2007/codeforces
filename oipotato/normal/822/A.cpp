#include<cstdio>
using namespace std;
int main()
{
	int A,B;
	scanf("%d%d",&A,&B);
	int ans=1;
	for(int i=2;i<=A&&i<=B;i++)ans*=i;
	printf("%d",ans);
	return 0;
}