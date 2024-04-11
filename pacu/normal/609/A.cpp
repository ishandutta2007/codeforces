#include <iostream>
#include <algorithm>
using namespace std;


int A[100];

int main()
{
	int N,M;
	cin >> N >> M;
	for(int i=0;i<N;i++)
		cin >> A[i];
	sort(A,A+N);
	int c = 0;
	int i = N-1;
	while(M > 0)
	{
		M -= A[i];
		c++;
		i--;
	}
	cout << c << '\n';
}