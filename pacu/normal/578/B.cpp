#include <cstdio>
#include <iostream>
using namespace std;

long long A[200000][11];
long long front[200000];
long long back[200000];

int main()
{
	int N,k,x;
	scanf("%d %d %d",&N,&k,&x);
	for(int i=0;i<N;i++)
	{
		scanf("%I64d",&A[i][0]);
		for(int j=1;j<=k;j++)
		{
			A[i][j] = A[i][j-1]*x;
		}
	}
	front[0] = A[0][0];
	for(int i=1;i<N;i++)
		front[i] = front[i-1] | A[i][0];
	back[N-1] = A[N-1][0];
	for(int i=N-2;i>=0;i--)
		back[i] = back[i+1] | A[i][0];
	long long best;
	if(N > 1)
		best = max((front[N-2] | A[N-1][k]),(A[0][k] | back[1]));
	else
		best = A[0][k];
	for(int i=1;i<N-1;i++)
		best = max(best,front[i-1] | A[i][k] | back[i+1]);
	printf("%I64d\n",best);
}