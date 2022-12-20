#include <iostream>
#include <algorithm>
using namespace std;

int A[100][100];
int N,M;
int low[100];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for(int i=0;i<N;i++)
		low[i] = 1000000000;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		{
			cin >> A[i][j];
			low[i] = min(low[i],A[i][j]);
		}
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(A[i][j]-low[i] != A[0][j]-low[0])
			{
				cout << -1 << '\n';
				return 0;
			}
	if(N > M)
	{
		int clow = 1000000000;
		for(int i=0;i<N;i++)
			clow = min(clow,low[i]);
		for(int i=0;i<N;i++)
			low[i] -= clow;
	}
	int num = 0;
	for(int i=0;i<N;i++)
		num += low[i];
	for(int j=0;j<M;j++)
		num += A[0][j]-low[0];
	cout << num << '\n';
	for(int i=0;i<N;i++)
		for(int c=0;c<low[i];c++)
			cout << "row " << i+1 << '\n';
	for(int j=0;j<M;j++)
		for(int c=0;c<A[0][j]-low[0];c++)
			cout << "col " << j+1 << '\n';
	return 0;
}