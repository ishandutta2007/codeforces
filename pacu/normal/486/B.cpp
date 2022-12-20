#include <iostream>
using namespace std;

int main()
{
	int A[100][100];
	int B[100][100];
	int M,N;
	cin >> N >> M;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		{
			cin >> A[i][j];
			B[i][j] = 1;
		}
	for(int x=0;x<N;x++)
		for(int y=0;y<M;y++)
		{
			if(A[x][y]) continue;
			for(int j=0;j<M;j++)
				B[x][j] = 0;
			for(int i=0;i<N;i++)
				B[i][y] = 0;
		}
	for(int x=0;x<N;x++)
		for(int y=0;y<M;y++)
		{
			if(!A[x][y]) continue;
			bool good = 0;
			for(int j=0;j<M;j++)
				good |= B[x][j];
			for(int i=0;i<N;i++)
				good |= B[i][y];
			if(!good)
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	cout << "YES" << endl;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
			cout << B[i][j] << " ";
		cout << endl;
	}
}