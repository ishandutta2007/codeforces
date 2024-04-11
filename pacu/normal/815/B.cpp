#include <iostream>
using namespace std;
#define MOD 1000000007

long long A[200000];
long long fact[200001];
long long mask[200001];

int pw(int a,int e)
{
	if(e==0) return 1;
	long long tmp = pw(a,e/2);
	tmp = (tmp*tmp)%MOD;
	if(e%2) tmp = (tmp*a)%MOD;
	return (int)tmp;
}

int inv(int a)
{
	return pw(a,MOD-2);
}

int ch(int n,int k)
{
	long long v = fact[n];
	v = (v*inv(fact[k]))%MOD;
	v = (v*inv(fact[n-k]))%MOD;
	return v;
}

int main()
{
	int N;
	cin >> N;
	fact[0] = 1;
	for(int i=1;i<=N;i++)
		fact[i] = (fact[i-1]*i)%MOD;
	if(N%4 == 1)
	{
		for(int k=0;k<=(N-1)/2;k++)
			mask[2*k] = ch((N-1)/2,k);
	}
	else if(N%4 == 2)
	{
		for(int k=0;k<=(N-2)/2;k++)
			mask[2*k] = mask[2*k+1] = ch((N-2)/2,k);
	}
	else if(N%4 == 0)
	{
		for(int k=0;k<=(N-2)/2;k++)
		{
			mask[2*k] = ch((N-2)/2,k);
			mask[2*k+1] = (MOD-mask[2*k])%MOD;
		}
	}
	else
	{
		for(int k=0;k<=(N-3)/2;k++)
			mask[2*k+1] = (2*ch((N-3)/2,k))%MOD;
		mask[0] = 1;
		mask[N-1] = MOD-1;
		for(int i=2;i<N-1;i+=2)
		{
			mask[i] = (mask[i+1] + MOD - mask[i-1])%MOD;
			if(mask[i]%2) mask[i] += MOD;
			mask[i] /= 2;
			mask[i] %= MOD;
		}
	}
	for(int i=0;i<N;i++)
		cin >> A[i];
	long long tot = 0;
	for(int i=0;i<N;i++)
		tot = (tot + mask[i]*A[i])%MOD;
	cout << tot << '\n';
}