#include<cstdio>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
bool ok[100010];
int sum,a[20],n;
bool fuck(int x,int y)
{
	return ((x-y)%360+360)%360==0;
}
int main()
{
	scanf("%d",&n);
	rep(i,n)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	ok[0]=1;
	rep(i,n)
	for(int j=sum;j>=a[i];j--)
	ok[j]|=ok[j-a[i]];
	rep(i,sum)if(ok[i]&&fuck(sum-i,i)){puts("YES");return 0;}
	puts("NO");
	return 0;
}