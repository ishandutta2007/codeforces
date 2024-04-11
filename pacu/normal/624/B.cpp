#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[26];

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	sort(A,A+N);
	long long tot = 0;
	int c = A[N-1];
	for(int i=N-1;i>=0;i--)
	{
		if(c>A[i]) c = A[i];
		if(c>=0) tot += c;
		c--;
	}
	cout << tot << '\n';
}