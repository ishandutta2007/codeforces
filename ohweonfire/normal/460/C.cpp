#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=100005;
int a[maxn],n,m,w;
ll prev[maxn];
bool chk(int ans)
{
	for(int i=1;i<=n;i++)
	{
		ll need=ans-a[i];
		need-=prev[i-1]-prev[max(0,i-w)];
		if(need<0)
			need=0;
		prev[i]=prev[i-1]+need;
	}
	if(prev[n]>m)
		return false;
	else
		return true;
}
void read()
{
	scanf("%d%d%d",&n,&m,&w);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
}
int binary()
{
	int l=0,r=1100000000;
	while(l<r-1)
	{
		int mid=(l*1ll+r)>>1;
		if(chk(mid))
			l=mid;
		else
			r=mid;
	}
	return l;
}
int main()
{
	read();
	printf("%d\n",binary());
	return 0;
}