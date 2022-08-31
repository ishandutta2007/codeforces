#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int st[100005],st2[100005],tp,tp2,n,a[100005];
int check(int k)
{
	st[1]=st2[1]=1;
	tp=tp2=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]-a[st[tp]]>k&&a[i]-a[st2[tp2]]>k) return 0;
		if(a[i]-a[st[tp]]>k)
			st2[++tp2]=i;
		else if(a[i]-a[st2[tp2]]>k)
			st[++tp]=i;
		else if(a[i]-a[st2[tp2]]>a[i]-a[st[tp]])
			st2[++tp2]=i;
		else st[++tp]=i;
	}
	/*printf("k=%d\n",k);
	for(int i=1;i<=tp;i++)
		printf("%d ",st[i]);
	printf("\n");
	for(int i=1;i<=tp2;i++)
		printf("%d ",st[i]);
	printf("\n\n");*/
	if(abs(a[st[tp]]-a[st2[tp2]])>k) return 0;
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int l=0,r=a[n],mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	//printf("l=%d,r=%d\n",l,r);
	check(l);
	for(int i=1;i<=tp;i++)
		printf("%d ",a[st[i]]);
	for(int i=tp2;i>1;i--)
		printf("%d ",a[st2[i]]);
	return 0;
}