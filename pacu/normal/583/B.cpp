#include <iostream>
using namespace std;

int A[1000];
int N;

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	int c = 0;
	for(int t=0;t<=N;t++)
	{
		if(t%2)
		{
			for(int i=N-1;i>=0;i--)
				if(A[i] <= c)
				{
					c++, A[i] = 50000;
				}
		}
		else
		{
			for(int i=0;i<N;i++)
				if(A[i] <= c)
				{
					c++, A[i] = 50000;
				}
		}
		if(c==N)
		{
			cout << t << '\n';
			return 0;
		}
	}
}