#include <iostream>
#include <algorithm>
using namespace std;

int N,K;
int A[2200];

int main()
{
	cin >> N >> K;
	for(int i=0;i<N;i++)
		cin >> A[i];
	sort(A,A+N);
	int ans = 0;
	for(int i=0;i<K;i++)
		ans += A[i];
	cout << ans << '\n';
}