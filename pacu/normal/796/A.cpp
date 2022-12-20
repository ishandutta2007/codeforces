#include <iostream>
#include <algorithm>
using namespace std;

int N,M,K;
int A[100];

int main()
{
	cin >> N >> M >> K;
	for(int i=0;i<N;i++)
		cin >> A[i];
	int ans = 10000;
	for(int i=0;i<N;i++)
		if(A[i]>0 && A[i]<=K)
			ans = min(ans,abs(M-1-i));
	cout << 10*ans << '\n';
	return 0;
}