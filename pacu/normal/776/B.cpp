#include <iostream>
using namespace std;

int N;

bool prime[100005];

int main()
{
	cin >> N;
	for(int i=1;i<=N+1;i++)
		prime[i] = 1;
	for(int i=2;i<=N+1;i++) if(prime[i])
	{
		for(int j=i*2;j<=N+1;j+=i)
			prime[j] = 0;
	}
	if(N <= 2) cout << 1 << '\n';
	else cout << 2 << '\n';
	for(int i=2;i<=N+1;i++)
		cout << 2-prime[i] << ' ';
	cout << '\n';
}