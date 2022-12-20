#include <iostream>
using namespace std;
#define MOD 1000000007

bool check(long long n,long long x,long long r)
{
	return n > r*(x+1);
}

long long half(long long v)
{
	v %= MOD;
	if(v%2) v += MOD;
	return v/2;
}

long long N,M;

int slow()
{
	long long ans = 0;
	for(long long i=1;i<=M;i++)
		ans = (ans + N%i)%MOD;
	return ans;
}

int main()
{
	cin >> N >> M;
	//cout << slow() << '\n';
	long long ans = 0;
	if(M>N) ans = ((N%MOD)*((M-N)%MOD))%MOD;
	M = min(M,N);
	ans = (ans + (N%MOD)*(M%MOD))%MOD;
	long long i;
	long long low = 1000000000000000;
	for(i=1;i<=M && i*i<=N;i++)
	{
		ans = (ans + MOD - (i*(N/i))%MOD)%MOD;
		//cout << i << ": " << (N/i) << '\n';
		low = min(low,N/i);
	}
	if(i>M)
	{
		cout << ans << '\n';
		return 0;
	}
	long long x = low-1;
	if(x*x==N) x--;
	long long a,b;
	for(;x>=1;x--)
	{
		a = N/x;
		long long r = ((N/x)-N%x)/(x+1);
		while((N/x) <= (x+1)*r + N%x) r--;
		while((N/x) > (x+1)*(r+1) + N%x) r++;
		b = (N/x)-r;
		swap(a,b);
		b = min(b,M);
		if(a<=b)
		{
			ans = (ans + MOD - (x*(half((b%MOD)*((b+1)%MOD))-half((a%MOD)*((a-1)%MOD))))%MOD)%MOD;
			//cout << a << "--" << b << ": " << x << '\n';
		}
	}
	cout << ans << '\n';
}