#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
#define MOD 1000000007

int N;
int A[500000];

int dp[10000001];
int pw[500001];

vector<int> primes;
bool isprime[3201];

vector<int> factors;
int prod[256];
int sign[256];
int dig[256];

int main()
{
	for(int i=2;i<=3200;i++) isprime[i] = 1;
	for(int i=2;i<=3200;i++)
	{
		if(isprime[i])
		{
			primes.push_back(i);
			for(int j=i+i;j<=3200;j+=i)
				isprime[j] = 0;
		}
	}
	
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		dp[A[i]]++;
	}
	
	for(int i=1;i<=10000000;i++)
		for(int j=i+i;j<=10000000;j+=i)
			dp[i] += dp[j];
			
	pw[0] = 1;
	for(int i=1;i<=N;i++)
		pw[i] = (2LL*pw[i-1])%MOD;
	sign[0] = 1;
	for(int i=1;i<256;i++)
		sign[i] = -sign[i-(i&-i)];
	dig[1] = 0;
	for(int i=2;i<256;i*=2)
		dig[i] = 1+dig[i/2];
		
	int ans = (2LL*((long long)N)*(pw[N-1]-1))%MOD;
//	printf("%d\n",ans);
	for(int i=0;i<N;i++)
	{
		factors.clear();
		int orig = A[i];
		for(int j=0;j<primes.size() && primes[j]*primes[j]<=orig;j++)
		{
			if(!(A[i]%primes[j]))
			{
				factors.push_back(primes[j]);
				while(!(A[i]%primes[j]))
					A[i] /= primes[j];
			}
		}
		if(A[i]>1) factors.push_back(A[i]);
		prod[0] = 1;
		for(int j=1;j<(1<<factors.size());j++)
		{
			prod[j] = prod[j-(j&-j)]*factors[dig[j&-j]];
			ans = (ans+2LL*sign[j]*(pw[dp[prod[j]]-1]-1))%MOD;
		}
//		printf("%d\n",ans);
	}
	
	for(int i=1;i<=10000000;i++)
		dp[i] = pw[dp[i]]-1;
	
	for(int i=10000000-1;i>=1;i--)
		for(int j=i+i;j<=10000000;j+=i)
			dp[i] = (dp[i]-dp[j])%MOD;
//	printf("%d\n",dp[1]);
	ans = (ans - ((long long)N)*dp[1])%MOD;
	ans = (MOD+(ans%MOD))%MOD;
	printf("%d\n",ans);
}