#include <iostream>
using namespace std;

int N;
int A[50][50];
int mx[50];

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin >> A[i][j];
			mx[i] = max(mx[i],A[i][j]);
		}
	}
	bool seen = 0;
	for(int i=0;i<N;i++)
	{
		if(mx[i] == N-1)
		{
			if(seen) cout << N << ' ';
			else cout << N-1 << ' ';
			seen = 1;
		}
		else
		{
			cout << mx[i] << ' ';
		}
	}
	cout << '\n';
}