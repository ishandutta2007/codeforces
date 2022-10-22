#include<cstdio>
using namespace std;

bool chk(int x)
{
	int ret=0;
	while(x)
	{
		ret+=x%10,x/=10;
		if(ret>10)
			return 0;
	}
	return ret==10;
}

int n;

int main()
{
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=100000000;i++)
		if(chk(i))
		{
			ans++;
			if(ans==n)
			{
				printf("%d",i); 
				break;
			}
		}
}