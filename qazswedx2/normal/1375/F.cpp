#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[3];
int b[3];
bool cmp(const int x,const int y)
{
	return a[x]<a[y];
}
int getnw(ll x)
{
	int y;
	printf("%lld\n",x);
	fflush(stdout);
	scanf("%d",&y);
	return y-1;
}
int main()
{
	for(int i=0;i<3;i++)
		scanf("%lld",&a[i]),b[i]=i;
	sort(b,b+3,cmp);
	sort(a,a+3);
	printf("First\n");
	fflush(stdout);
	int q=getnw(a[2]-a[0]);
	if(q==b[2])
	{
		a[2]+=a[2]-a[0];
		q=getnw(a[2]+a[2]-a[0]-a[1]);
		if(q==b[1])
			getnw(a[2]-a[0]);
		else getnw(a[2]-a[1]);
	}
	else
	{
		a[1]+=a[2]-a[0];
		q=getnw(a[1]+a[1]-a[0]-a[2]);
		if(q==b[0])
			getnw(a[1]-a[2]);
		else getnw(a[1]-a[0]);
	}
	return 0;
}