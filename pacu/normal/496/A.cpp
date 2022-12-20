#include <iostream>
using namespace std;

int A[100];
int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	int iBest = 1;
	for(int i=1;i<(N-1);i++)
		if((A[i+1]-A[i-1])<(A[iBest+1]-A[iBest-1]))
			iBest = i;
	int ans = A[iBest+1]-A[iBest-1];
	for(int i=1;i<N;i++)
		ans = max(ans,A[i]-A[i-1]);
	cout << ans << endl;
	return 0;
}