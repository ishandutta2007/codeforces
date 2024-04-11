#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	int A[3000];
	int B[3000];
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		B[i] = A[i];
	}
	sort(B,B+N);
	cout << N << endl;
	for(int i=0;i<N;i++)
	{
		int j;
		for(j=i;j<N;j++)
			if(A[j]==B[i])
				break;
		swap(A[i],A[j]);
		cout << i << " " << j << endl;
	}
}