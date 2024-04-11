#include <cstdio>
using namespace std;

int A[2000000];
int N;

int mq[2000001];
int end,start;

int binSearch(int low,int high,int v)
{
	if(low==high) return low;
	if((low+1)==high)
	{
		if(A[mq[high]%N] > v) return high;
		return low;
	}
	int mid = (low+high)/2;
	if(A[mq[mid]%N] > v) return binSearch(mid,high,v);
	else return binSearch(low,mid-1,v);
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		A[i+N] = A[i];
	}
	long long ans = 0;
	end = 0, start = 0;
	int f,srun;
	for(int i=0;i<2*N;i++)
	{
		while((end>start)&&((i-mq[start])>=N))
			start++;
//		printf("-----%d\n",i);
//		for(int j=start;j<end;j++)
//			printf("%d ",mq[j]);
//		printf("\n");
		if(end>start)
		{
			f = srun-binSearch(start,end-1,A[i]);
//			printf("%d\n",f);
			if(f>=0)
				ans += f;
		}
		while((end>start)&&(A[i] > A[mq[end-1]%N]))
			end--;
		if(i>=N)
		{
			if((end==start)||(mq[end-1]<N))
				srun = end;
		}
		else
			srun = end+1;
		mq[end++] = i;
	}
	int b1 = 0;
	long long n1 = 0;
	int b2 = 0;
	long long n2 = 0;
	for(int i=0;i<N;i++)
	{
		if(A[i] > b1)
		{
			b2 = b1;
			n2 = n1;
			b1 = A[i];
			n1 = 1;
		}
		else if(A[i] == b1)
			n1++;
		else if(A[i] > b2)
		{
			b2 = A[i];
			n2 = 1;
		}
		else if(A[i] == b2)
			n2++;
	}
	if(n1 > 1)
		ans -= (n1*(n1-1))/2;
	else if(n1 == 1)
		ans -= n2;
	printf("%I64d\n",ans);
	return 0;
}