#include <iostream>
using namespace std;
#define MOD 1000000007

long long cnt[200001];
int M;

long long p1[200001],p2[200001];

long long exp(long long a,long long pw)
{
	if(pw==0) return 1;
	long long tmp = exp(a,pw/2);
	tmp = (tmp*((long long)tmp))%MOD;
	if(pw%2) tmp = (tmp*((long long)a))%MOD;
	return tmp;
}

int main()
{
	cin >> M;
	int a;
	for(int i=0;i<M;i++)
	{
		cin >> a;
		cnt[a]++;
	}
	p1[0] = 1;
	for(int i=1;i<=200000;i++)
		p1[i] = (p1[i-1]*((long long)(1+cnt[i])))%(MOD-1);
	p2[200000] = 1;
	for(int i=200000-1;i>=0;i--)
		p2[i] = (p2[i+1]*((long long)(1+cnt[i])))%(MOD-1);
	long long ans = 1;
	for(int i=1;i<200000;i++)
	{
		long long c = exp(i,(cnt[i]*((long long)(1+cnt[i])))/2);
		c = exp(c,p1[i-1]);
		c = exp(c,p2[i+1]);
		ans = (ans*((long long)c))%MOD;
	}
	cout << ans << '\n';
}