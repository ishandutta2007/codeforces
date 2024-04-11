#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int gcd(int x,int y)
{
	if(!y) return x;
	return gcd(y,x%y);
}
int n,x,y,xx,yy;
ll a,b;
int main()
{
	scanf("%d%d%d%d%d",&n,&x,&y,&xx,&yy);
	if(y<0) x=-x,y=-y;
	if(yy<0) xx=-xx,yy=-yy;
	if(1ll*x*yy-1ll*y*xx==0)
	{
		printf("NO\n");
		return 0;
	}
	int g=gcd(y,yy);
	b=g;
	a=1ll*yy/g*x-1ll*y/g*xx;
	if(a<0) a=-a;
	if(1ll*a*b!=n) printf("NO\n");
	else
	{
		printf("YES\n");
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
				printf("%d %d\n",i,j);
	}
	return 0;
}