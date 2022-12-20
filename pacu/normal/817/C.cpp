#include <iostream>
using namespace std;

long long N,S;

int sdig(long long v)
{
	int ans = 0;
	while(v>0)
	{
		ans += v%10;
		v /= 10;
	}
	return ans;
}

int main()
{
	cin >> N >> S;
	long long low = 1;
	long long high = N+1;
	while(low != high)
	{
		long long mid = (low+high)/2;
		if(mid - sdig(mid) < S)
			low = mid+1;
		else
			high = mid;
	}
	cout << N + 1 - low << '\n';
}