#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool check(int x)
{
	int ans=0;
	while(x)
	{
		ans+=x%10;
		x/=10;
	}
	if(ans%4==0) return 1;
	return 0;
}
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=a;;i++)
	{
		if(check(i))
		{
			printf("%d",i);
			return 0;
		}
	}
}