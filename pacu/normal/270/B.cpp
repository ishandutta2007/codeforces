#include <iostream>
using namespace std;

int A[100000];
int N;

int main()
{
	int ans = 1;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int i=N-2;i>=0;i--)
	{
		if(A[i] > A[i+1])
			break;
		ans++;
	}
	cout << N-ans << endl;
	return 0;
}