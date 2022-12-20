#include <iostream>
#include <vector>
using namespace std;

int ans[100];

int main()
{
	vector<int> A;
	int N,M;
	int i,j;
	cin >> N >> M;
	for(i=0;i<M;i++)
	{
		A.push_back(0);
		cin >> A[i];
		A[i]--;
	}
	for(i=(M-1);i>=0;i--)
	{
		for(j=(N-1);j>=A[i];j--)
			ans[j] = A[i];
	}
	for(j=0;j<N;j++)
		cout << ans[j]+1 << " ";
}