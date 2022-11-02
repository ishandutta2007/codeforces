#include <cstdio>
#include <algorithm>
using namespace std;
int a[10],ans;
int main()
{
	for(int i=1;i<=6;i++)
		a[i]=getchar()-'0';
	ans=6;
	for(int i=0;i<=27;i++)
	{
		int num1,num2;
		if(a[1]+a[2]+a[3]==i)
			num1=0;
		else if(0<=i-a[1]-a[2]&&i-a[1]-a[2]<=9||0<=i-a[1]-a[3]&&i-a[1]-a[3]<=9||0<=i-a[2]-a[3]&&i-a[2]-a[3]<=9)
			num1=1;
		else if(0<=i-a[1]&&i-a[1]<=18||0<=i-a[2]&&i-a[2]<=18||0<=i-a[3]&&i-a[3]<=18)
			num1=2;
		else
			num1=3;
		if(a[4]+a[5]+a[6]==i)
			num2=0;
		else if(0<=i-a[4]-a[5]&&i-a[4]-a[5]<=9||0<=i-a[4]-a[6]&&i-a[4]-a[6]<=9||0<=i-a[5]-a[6]&&i-a[5]-a[6]<=9)
			num2=1;
		else if(0<=i-a[4]&&i-a[4]<=18||0<=i-a[5]&&i-a[5]<=18||0<=i-a[6]&&i-a[6]<=18)
			num2=2;
		else
			num2=3;
		ans=min(ans,num1+num2);
	}
	printf("%d\n",ans);
	return 0;
}