#include <iostream>
using namespace std;

int A[100][4];

int main()
{
	int N,M;
	cin >> N >> M;
	for(int i=0;i<N;i++)
	{
		A[i][0] = 2*i + 1;
		A[i][3] = 2*i + 2;
		A[i][1] = 2*N+1+2*i;
		A[i][2] = 2*N+2+2*i;
	}
	for(int i=0;i<N;i++)
	{
		if(A[i][1]<=M) cout << A[i][1] << ' ';
		if(A[i][0]<=M) cout << A[i][0] << ' ';
		if(A[i][2]<=M) cout << A[i][2] << ' ';
		if(A[i][3]<=M) cout << A[i][3] << ' ';
	}
	cout << '\n';
}