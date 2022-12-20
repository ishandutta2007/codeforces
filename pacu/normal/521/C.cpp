#include <iostream>
#include <string>
using namespace std;
#define MOD 1000000007LL
#define MOD 1000000007

long long nck[100005];
long long nck2[100005];
long long ten[100005];

long long inv(long long a,long long pw)
{
	if(pw==0LL) return 1LL;
	if(pw==1LL) return a;
	long long p = inv(a,pw/2LL);
	p = (p*p)%MOD;
	if(pw%2LL) return (a*p)%MOD;
	else return p;
}

int main()
{
	long long N,K;
	string s;
	cin >> N >> K >> s;
	long long nfst = K-1LL;
	long long kfst = K-1LL;
	nck[N-K-1] = 1LL;
	for(long long i=(N-K-2);i>=0;i--)
	{
		nfst++;
		nck[i] = (nfst*nck[i+1])%MOD;
		nck[i] = (nck[i]*inv(nfst-kfst,MOD-2LL))%MOD;
	}

	ten[0] = 1LL;
	for(long long i=1;i<N;i++)
		ten[i] = (ten[i-1]*10LL)%MOD;

	nck2[K] = 1LL;
	for(long long i=K+1;i<N;i++)
	{
		nck2[i] = (i*nck2[i-1])%MOD;
		nck2[i] = (nck2[i]*inv(i-K,MOD-2))%MOD;
	}
	long long ans = 0LL;
	long long psum = 0LL;
	for(long long i=(N-1);i>=0;i--)
	{
		if(i>=K)
			ans += (((long long)(s[i]-'0'))*((psum + (nck2[i]*ten[N-1-i])%MOD)%MOD))%MOD;
		else
			ans += (psum*((long long)(s[i]-'0')))%MOD;
		if(i>=K)
			psum = (psum + (nck[N-1-i]*ten[N-1-i])%MOD)%MOD;
		ans %= MOD;
	}
	ans %= MOD;
	cout << ans << endl;
	return 0;
}