#include <iostream>
using namespace std;

int A[100000];
int B[100000];
int N;

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	int m = 0;
	for(int i=N-1;i>=0;i--)
	{
		B[i] = max(0,m+1-A[i]);
		m = max(m,A[i]);
	}
	for(int i=0;i<N;i++)
		cout << B[i] << ' ';
	cout << '\n';
}