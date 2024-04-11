#include<cstdio>
#include<algorithm>
using namespace std;
int a[100010],b[100010],n,S;
bool check(int x)
{
	for(int i=1;i<=n;i++)b[i]=min(a[i]+(long long)x*i,(long long)S+1);
	sort(b+1,b+n+1);
	int tmp=0;
	for(int i=1;i<=x;i++)
	if(tmp+b[i]>S)return 0;
	else tmp+=b[i];
	return 1;
}
int cal(int x)
{
	for(int i=1;i<=n;i++)b[i]=min(a[i]+(long long)x*i,(long long)S+1);
	sort(b+1,b+n+1);
	int tmp=0;
	for(int i=1;i<=x;i++)tmp+=b[i];
	return tmp;
}
int main()
{
	scanf("%d%d",&n,&S);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int l=0,r=n+1;
	for(;l<r-1;)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	printf("%d %d\n",l,cal(l));
	return 0;
}