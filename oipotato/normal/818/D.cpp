#include<cstdio>
#include<algorithm>
using namespace std;
int cnt[1000010],heap[1000010],n,x,A,num,b[1000010];
void down(int x)
{
	int p=x<<1;
	if(p<num&&cnt[heap[p]]>cnt[heap[p+1]])p++;
	for(;p<=num;)
	if(cnt[heap[p]]<cnt[heap[x]])
	{
		swap(heap[p],heap[x]);
		swap(b[heap[p]],b[heap[x]]);
		x=p;
		p<<=1;
		if(p<num&&cnt[heap[p]]>cnt[heap[p+1]])p++;
	}
	else break;
}
int main()
{
	scanf("%d%d",&n,&A);
	num=1000000;
	for(int i=1;i<=num;i++)heap[i]=i,b[i]=i;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(b[x])
		{
			cnt[x]++;
			down(b[x]);
		}
		for(;cnt[heap[1]]<cnt[A];)
		{
			b[heap[1]]=0;
			heap[1]=heap[num--];
			b[heap[1]]=1;
			down(1);
		}
		if(num==1)
		{
			printf("-1");
			return 0;
		}
	}
	printf("%d",heap[num]!=A?heap[num]:heap[1]);
	return 0;
}