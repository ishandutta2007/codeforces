#include <iostream>
#include <algorithm>
using namespace std;

int N;
int v[200000];
int cnt[200001];
long long A[200002];
long long B[200002];
long long smod[200002];

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> v[i];
		cnt[v[i]]++;
	}
	for(int i=200000;i>=0;i--)
	{
		A[i] = A[i+1] + cnt[i];
		B[i] = B[i+1] + A[i+1];
	}
	for(int i=1;i<=200000;i++)
	{
		smod[i] = B[0];
		for(int j=i;j<=200000;j+=i)
			smod[i] -= i*A[j];
	}
	long long ans = 0;
	for(int i=0;i<N;i++)
		ans = max(ans,B[0]-smod[v[i]]);
	cout << ans << '\n';
}