#include <iostream>
using namespace std;

int N,M,Q;

int dx[100][100],dy[100][100];
int nx[100][100],ny[100][100];

int A[100][100];

int main()
{
	cin >> N >> M >> Q;
	int t,r,c,x;
	for(int i=0;i<N;i++) for(int j=0;j<M;j++) dx[i][j] = i, dy[i][j] = j;
	for(int i=0;i<Q;i++)
	{
		cin >> t;
		if(t==1)
		{
			cin >> r;
			r--;
			for(int j=0;j<M;j++)
				nx[r][j] = dx[r][(j+1)%M], ny[r][j] = dy[r][(j+1)%M];
			for(int j=0;j<M;j++)
				dx[r][j] = nx[r][j], dy[r][j] = ny[r][j];
		}
		else if(t==2)
		{
			cin >> c;
			c--;
			for(int j=0;j<N;j++)
				nx[j][c] = dx[(j+1)%N][c], ny[j][c] = dy[(j+1)%N][c];
			for(int j=0;j<N;j++)
				dx[j][c] = nx[j][c], dy[j][c] = ny[j][c];
		}
		else if(t==3)
		{
			cin >> r >> c >> x;
			r--,c--;
			A[dx[r][c]][dy[r][c]] = x;
		}
	}
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
			cout << A[i][j] << ' ';
		cout << '\n';
	}
}