#include<cstdio>
using namespace std;
bool ok[500];
int p,x,y,ans;
bool check(int x){return ok[x/50%475];}
int main()
{
	scanf("%d%d%d",&p,&x,&y);
	for(int i=0;i<475;i++)
	{
		int tmp=i;
		for(int j=1;j<=25;j++)
		{
			tmp=(tmp*96+42)%475;
			if(tmp+26==p)ok[i]=1;
		}
	}
	for(int i=x;i>=y;i-=50)
	if(check(i))
	{
		printf("0");
		return 0;
	}
	for(int i=x+50,ans=1;;i+=100,ans++)
	if(check(i)||check(i+50))
	{
		printf("%d",ans);
		return 0;
	}
	return 0;
}