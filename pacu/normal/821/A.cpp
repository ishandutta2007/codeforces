#include <iostream>
#include <algorithm>
using namespace std;

int A[50][50];

int N;

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> A[i][j];
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			bool good = (A[i][j]==1);
			for(int k=0;k<N;k++)
				for(int l=0;l<N;l++)
					if(A[i][k]+A[l][j] == A[i][j])
						good = 1;
			if(!good)
			{
				cout << "No\n";
				return 0;
			}
		}
	cout << "Yes\n";
	return 0;
}