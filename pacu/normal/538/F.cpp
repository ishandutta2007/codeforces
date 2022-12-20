#include <cstdio>
using namespace std;

int A[300001];
int ans[300001];
int dif[300001];
int N;

long long check(long long k)
{
	long long a = 0;
	for(long long i=1;i<N;i++)
		if(A[i] < A[(i-1)/k])
			a++;
	return a;
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	int parent,k;
	int low,high;
	for(int i=1;i<N;i++)
	{
		for(k=1;(k*k)<=N && (k<N);k++)
		{
			if(A[i] < A[(i-1)/k])
				ans[k]++;
		}
		for(parent=0;(parent*parent<=(N)) && (parent<i);parent++)
		{
			if(A[i] < A[parent])
			{
				low = (i-1)/(parent+1);
				if((i-1)>=(low*(parent+1)))
					low++;
				if(parent==0)
					high = N-1;
				else
					high = (i-1)/parent;
				dif[low]++;
				dif[high+1]--;
			}
		}
	}
	int cur = dif[0];
	for(int k=1;k<N;k++)
	{
		cur += dif[k];
		if((k*((long long)k))<=(N))
			printf("%d ",ans[k]);
		else
			printf("%d ",ans[k]+cur);
	}
	printf("\n");

	/*
	for(long long k=1;k<N;k++)
		cout << check(k) << " ";
	cout << "\n";*/
	return 0;
}