#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000007

int N;
int A[500][500];

int dpEdge[500][500];
int dpLeft[500][500];
int dpRight[500][500];

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> A[i][j];
	for(int i=0;i<N;i++)
	{
		dpEdge[i][(i+1)%N] = dpLeft[i][(i+1)%N] = dpRight[i][(i+1)%N] = A[i][(i+1)%N];
		dpLeft[i][i] = dpRight[i][i] = 1;
	}
	for(int d=2;d<N;d++)
	{
		for(int i=0;i<N;i++)
		{
			int j = (i+d)%N;
			//Edge
			if(A[i][j])
			{
				for(int k=i;k!=j;k=(k+1)%N)
					dpEdge[i][j] = (dpEdge[i][j] + dpLeft[i][k]*((long long)dpRight[(k+1)%N][j]))%MOD;
			}
			//Left
			for(int k=i;k!=j;k=(k+1)%N)
				dpLeft[i][j] = (dpLeft[i][j] + dpEdge[k][j]*((long long)dpLeft[i][k]))%MOD;
			//Right
			for(int k=j;k!=i;k=(k+N-1)%N)
				dpRight[i][j] = (dpRight[i][j] + dpEdge[i][k]*((long long)dpRight[k][j]))%MOD;
		}
	}
	cout << dpLeft[1][0] << '\n';
}