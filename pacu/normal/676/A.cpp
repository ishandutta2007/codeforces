#include <iostream>
#include <cmath>
using namespace std;

int A[100];

int main()
{
	int N;
	cin >> N;
	int x = 0;
	int y = 0;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		if(A[i]==1) x=i;
		else if(A[i]==N) y=i;
	}
	cout << max(N-1-min(x,y),max(x,y)) << '\n';
}