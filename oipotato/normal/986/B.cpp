#include<cstdio>
#include<algorithm>
using namespace std;
int c[1000010],n,a[1000010];
long long ans;
void modify(int x){for(;x<=n;x+=x&(-x))c[x]++;}
int get(int x){int s=0;for(;x;x-=x&(-x))s+=c[x];return s;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=n;i;i--)
	{
		ans+=get(a[i]);
		modify(a[i]);
	}
	if((ans&1)==(n&1))puts("Petr");else puts("Um_nik");
	return 0;
}