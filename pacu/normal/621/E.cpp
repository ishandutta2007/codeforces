#include <iostream>
using namespace std;

long long ways[31][100];
int A[50000];
int N,B,K,X;
long long tmp[100];
long long ans[100];
long long pw[31];

int main()
{
	cin >> N >> B >> K >> X;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		ways[0][A[i]%X]++;
	}
	pw[0] = 10%X;
	for(int i=1;i<30;i++)
	{
		pw[i] = (pw[i-1]*pw[i-1])%X;
		for(int j=0;j<X;j++)
			tmp[j] = 0;
		for(int j=0;j<X;j++)
			tmp[(j*pw[i-1])%X] = (tmp[(j*pw[i-1])%X]+ways[i-1][j])%1000000007;
		for(int j=0;j<X;j++)
			for(int k=0;k<X;k++)
				ways[i][j] = (ways[i][j] + ways[i-1][k]*tmp[(j+X-k)%X])%1000000007;
	}
	ans[0] = 1;
	long long cpw = 1;
	for(int i=0;i<30;i++)
	{
		if(!(B&(1<<i))) continue;
		for(int j=0;j<X;j++)
			tmp[j] = 0;
		for(int j=0;j<X;j++)
			tmp[(j*pw[i])%X] = (tmp[(j*pw[i])%X]+ans[j])%1000000007;
		for(int j=0;j<X;j++)
			ans[j] = 0;
		for(int j=0;j<X;j++)
			for(int k=0;k<X;k++)
				ans[j] = (ans[j] + ways[i][k]*tmp[(j+X-k)%X])%1000000007;
		cpw = (cpw*pw[i])%X;
	}
	cout << ans[K] << '\n';
}