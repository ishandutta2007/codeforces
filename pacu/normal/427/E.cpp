#include <iostream>
using namespace std;

long long A[1000000];

int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
		scanf("%I64d",&A[i]);
	long long cnt = 0;
	for(int i=0;i<=N/2;i+=M)
		cnt += A[N/2]-A[i];
	for(int i=(N-1);i>=N/2;i-=M)
		cnt += A[i]-A[N/2];
	cout << 2*cnt << endl;
}