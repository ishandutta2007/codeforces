
#include <iostream>
#include <algorithm>
using namespace std;

int A[1000];
int N;

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	int cnt = 0;
	for(int i=1;i<N-1;i++)
		if((A[i]<A[i-1] && A[i]<A[i+1]) || (A[i]>A[i-1] && A[i]>A[i+1]))
			cnt++;
	cout << cnt << '\n';
}