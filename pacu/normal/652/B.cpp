#include <iostream>
#include <algorithm>
using namespace std;

int A[1000];
int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	sort(A,A+N);
	int l = 0;
	int r = N-1;
	for(int i=0;i<N;i++)
	{
		if(i%2) cout << A[r--] << ' ';
		else cout << A[l++] << ' ';
	}
	cout << '\n';
}