#include <iostream>
#include <algorithm>
using namespace std;

int A[1<<18];
int B[1<<18];
int lc[1<<18];

int N,M;
int x[35];

int main()
{
	for(int i=0;i<18;i++)
		lc[1<<i] = i;
	cin >> N >> M;
	for(int i=0;i<N;i++)
		cin >> x[i];
	int K = N/2;
	A[0] = 0;
	for(int i=1;i<(1<<K);i++)
		A[i] = (A[i-(i&-i)] + x[lc[i&-i]])%M;
	B[0] = 0;
	for(int i=1;i<(1<<(N-K));i++)
		B[i] = (B[i-(i&-i)] + x[lc[i&-i]+K])%M;
	sort(A,A+(1<<K));
	sort(B,B+(1<<(N-K)));
	int ans = 0;
	for(int i=0;i<(1<<K);i++)
	{
		int j = lower_bound(B,B+(1<<(N-K)),M-A[i])-B;
		if(j>0) j--;
		else j = (1<<(N-K))-1;
		ans = max(ans,(A[i]+B[j])%M);
		ans = max(ans,(A[i]+B[(1<<(N-K))-1])%M);
	}
	cout << ans << '\n';
}