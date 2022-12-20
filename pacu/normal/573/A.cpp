#include <iostream>
using namespace std;

int A[100000];

int N;

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		while(!(A[i]%2)) A[i] /= 2;
		while(!(A[i]%3)) A[i] /= 3;
	}
	for(int i=0;i<N;i++)
	{
		if(A[i] != A[0])
		{
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}