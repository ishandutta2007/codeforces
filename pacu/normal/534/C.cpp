#include <iostream>
using namespace std;

long long d[200000];
long long N,A;

int main()
{
	cin >> N >> A;
	long long s = 0;
	for(int i=0;i<N;i++)
	{
		cin >> d[i];
		s += (long long)d[i];
	}
	for(int i=0;i<N;i++)
	{
		long long low = max(1LL,A - (s - d[i]));
		long long high = min(d[i],A - (N - 1));
		cout << d[i] - (high+1-low) << ' ';
	}
	cout << '\n';
}