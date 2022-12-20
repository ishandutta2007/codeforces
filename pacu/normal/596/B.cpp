#include <iostream>
#include <cmath>
using namespace std;

long long A[200001];
long long B[200001];

int main()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> B[i];
	long long ans = abs(B[0]);
	for(int i=1;i<N;i++)
		ans += (long long)abs(B[i]-B[i-1]);
	cout << ans << '\n';
}