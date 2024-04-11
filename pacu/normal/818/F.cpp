#include <iostream>
#include <cmath>
using namespace std;

long long N;

long long getClique(long long d)
{
	if((N*(N-3))/2 < d) return N;
	long long k = (3.0 + sqrt(9 + 8*d))/2.0;
	if((k*(k-3))/2 < d) k++;
	return k;
}

int main()
{
	int Q;
	cin >> Q;
	while(Q--)
	{
		cin >> N;
		if(2*(N-3) < N) cout << N-1 << '\n';
		else
		{
			long long low = N;
			long long high = (N*(N-1))/2;
			while(low != high)
			{
				long long mid = (low+high+1)/2;
				long long k = getClique(mid-N);
				if(2*(N-k) >= mid) low = mid;
				else high = mid-1;
			}
			cout << low << '\n';
		}
	}
}