#include<cstdio>
int l[200001],r[200001],n,ll[200001],rr[200001],len[200001];
long long sum,l1,r1;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		r[i]=r[i]+l[i];
	}
	l1=0;
	r1=2000001;
	for(int i=1;i<=n;i++)
	{
		l1=l1-1;
		if(l1<l[i]) l1=l[i];
		r1=r1+1;
		if(r1>r[i]) r1=r[i];
		if(l1>r1) break; 
		ll[i]=l1;
		rr[i]=r1;
	}
	if(l1>r1) printf("-1");
	else
	{
		sum=0;
		for(int i=n;i>=1;i--)
		{
			if(ll[i]>l1) l1=ll[i];
			if(rr[i]<r1) r1=rr[i];
			sum=sum+r1-l[i];
			len[i]=r1;
			l1=r1-1;
			r1++;
		}
		printf("%I64d\n",sum);
		for(int i=1;i<=n;i++) printf("%d ",len[i]);
	}
}