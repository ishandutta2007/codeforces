#include <iostream>
using namespace std;

int w[400][400];

int rail[400][400];

int N,M;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> M;
	int a,b;
	for(int i=0;i<M;i++)
	{
		cin >> a >> b;
		a--,b--;
		rail[a][b] = rail[b][a] = 1;
	}
	if(rail[0][N-1]==1)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(rail[i][j]) w[i][j] = 1000000;
				else w[i][j] = 1;
			}
		}
	}
	else
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(rail[i][j]) w[i][j] = 1;
				else w[i][j] = 1000000;
			}
		}	
	}
	for(int i=0;i<N;i++)
		w[i][i] = 0;
	for(int k=0;k<N;k++)
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				w[i][j] = min(w[i][j],w[i][k]+w[k][j]);
	if(w[0][N-1] == 1000000)
		cout << -1 << '\n';
	else
		cout << w[0][N-1] << '\n';
}