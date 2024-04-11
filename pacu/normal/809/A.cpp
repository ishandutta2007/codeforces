#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MOD 1000000007

int pw[300001];
int N;
int x[300000];

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&x[i]);
	sort(x,x+N);
	pw[0] = 1;
	for(int i=1;i<=N;i++)
		pw[i] = (2*pw[i-1])%MOD;
	long long ans = 0;
	for(int i=0;i<N;i++)
	{
		ans = (ans + x[i]*((long long)(pw[i]+MOD-1)))%MOD;
		ans = (ans + MOD - (x[i]*((long long)(pw[N-1-i]+MOD-1)))%MOD)%MOD;
	}
	printf("%d\n",(int)ans);
	return 0;
}