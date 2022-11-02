#include<cstdio>
#include<algorithm>
using namespace std;
int heap[1000010],a[1000010],k,n,num;
long long tans,ans;
void up(int x)
{
	int p=x>>1;
	for(;p>=1;)
	if(heap[p]>heap[x])
	{
		swap(heap[p],heap[x]);
		x=p;
		p>>=1;
	}
	else break;
}
void down(int x)
{
	int p=x<<1;
	if(p<num&&heap[p]>heap[p+1])p++;
	for(;p<=num;)
	if(heap[p]<heap[x])
	{
		swap(heap[p],heap[x]);
		x=p;
		p<<=1;
		if(p<num&&heap[p]>heap[p+1])p++;
	}
	else break;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>i)
		{
			tans+=a[i]-i;
			heap[++num]=a[i]-i;
			up(num);
		}
		else tans+=i-a[i];
	}
	ans=tans;k=0;
	for(int i=1;i<n;i++)
	{
		tans+=n-1-2*num;
		if(a[n-i+1]>1)
		{
			tans+=a[n-i+1]-1-n+a[n-i+1];
			heap[++num]=a[n-i+1]-1+i;
			up(num);
		}
		else tans-=n-1;
		if(tans<ans)ans=tans,k=i;
		for(;num&&heap[1]<=i;)
		{
			heap[1]=heap[num--];
			down(1);
		}
	}
	printf("%I64d %d",ans,k);
	return 0;
}