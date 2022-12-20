#include <cstdio>
using namespace std;

int A[1000000];
int back[1000000];
long long total;
int N;

int solve(long long b)
{
	if(total <= b) return 1;
	int j = N-1;
	long long cursum = A[0];
	while((cursum+A[j])<=b)
	{
		cursum += A[j];
		j--;
	}
	back[0] = j;
	int low = 0;
	for(int i=1;i<N;i++)
	{
		cursum += A[i];
		while(cursum > b)
		{
			j = (j+1)%N;
			cursum -= A[j];
		}
		back[i] = j;
		if((low+N-back[low])%N > (i+N-back[i])%N)
			low = i;
	}
	int bestans = N;
	int curans,distCovered;
	int cur;
	for(int start=back[low];start!=low;start=(start+1)%N)
	{
		cur = start;
		curans = 0;
		distCovered = 0;
		while(distCovered < N)
		{
			distCovered += (cur+N-back[cur])%N;
			cur = back[cur];
			curans++;
		}
		if(curans<bestans)
			bestans = curans;
	}
	return bestans;
}

int main()
{
	int Q;
	scanf("%d %d",&N,&Q);
	total = 0;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		total += A[i];
	}
	long long b;
	for(int i=0;i<Q;i++)
	{
		scanf("%I64d",&b);
		printf("%d\n",solve(b));
	}
}