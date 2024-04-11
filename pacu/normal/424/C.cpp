#include <iostream>
using namespace std;

int sm[1000001];
int N;

int main()
{
	cin >> N;
	int x = 0;
	int a;
	for(int i=0;i<N;i++)
	{
		cin >> a;
		x ^= a;
	}
	sm[0] = 0;
	for(int i=1;i<=N;i++)
		sm[i] = sm[i-1]^i;
	for(int i=1;i<=N;i++)
	{
		if((N/i)&1)
			x ^= sm[i-1];
		x ^= sm[N%i];
	}
	cout << x << '\n';
}