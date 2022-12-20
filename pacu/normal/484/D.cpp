#include <cstdio>
#include <iostream>
using namespace std;

int A[1000000];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	long long bestInc = -A[0];
	long long bestDec = A[0];
	long long dp = 0;
	for(int i=0;i<N;i++)
	{
		bestInc = max(bestInc,dp-A[i]);
		bestDec = max(bestDec,dp+A[i]);
		dp = max(bestInc+A[i],bestDec-A[i]);
	}
	cout << dp << endl;
}