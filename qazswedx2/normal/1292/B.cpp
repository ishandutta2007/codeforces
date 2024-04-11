#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef long long ll;
ll sx,sy,t,x,y,ax,ay,bx,by,a[100005],b[100005],at;
ll getans(ll x)
{
	return x>=0?x:-x;
}
int main()
{
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&x,&y,&ax,&ay,&bx,&by);
	scanf("%I64d%I64d%I64d",&sx,&sy,&t);
	at=1;
	a[1]=x,b[1]=y;
	while(1)
	{
		at++;
		a[at]=a[at-1]*ax+bx,b[at]=b[at-1]*ay+by;
		if(a[at]>=2e16||b[at]>=2e16) 
		{
			if(a[at]>=2e17||b[at]>=2e17) at--;
			break;
		}
	}
	//for(int i=1;i<=at;i++)
	//	printf("%I64d %I64d\n",a[i],b[i]);
	int ans=0;
	for(int i=1;i<=at;i++)
		for(int j=1;j<=at;j++)
			if(getans(a[i]-sx)+getans(b[i]-sy)+getans(a[j]-a[i])+getans(b[j]-b[i])<=t)
				ans=max(ans,(int)getans(j-i)+1);
	printf("%d\n",ans);
	return 0;
}