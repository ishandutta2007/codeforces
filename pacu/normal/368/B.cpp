#include <iostream>
using namespace std;

int N,M;
int A[100000];
int B[100000];
int C[100001];
int ans[100000];

int main()
{
	cin >> N >> M;
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int i=0;i<M;i++)
		cin >> B[i];
	ans[N-1] = C[A[N-1]] = 1;
	for(int i=N-2;i>=0;i--)
	{
		ans[i] = ans[i+1];
		if(C[A[i]] == 0)
		{
			C[A[i]] = 1;
			ans[i]++;
		}
	}
	for(int i=0;i<M;i++)
		cout << ans[B[i]-1] << endl;
	return 0;
}