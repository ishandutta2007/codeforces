#include <iostream>
using namespace std;

long long A[200001];
long long sm[200001];
long long hpref[200001];
int N,K;

int main()
{
	cin >> N >> K;
	for(int i=1;i<=N;i++)
		cin >> A[i];
	sm[0] = 0;
	for(int i=1;i<=N;i++)
		sm[i] = sm[i-1] + A[i];
	hpref[K] = K;
	for(int i=K+1;i<=N;i++)
	{
		if((sm[i]-sm[i-K])>(sm[hpref[i-1]]-sm[hpref[i-1]-K]))
			hpref[i] = i;
		else
			hpref[i] = hpref[i-1];
	}
	int a = 1;
	int b = K+1;
	for(int i=2*K;i<=N;i++)
	{
		if(((sm[i]-sm[i-K])+(sm[hpref[i-K]]-sm[hpref[i-K]-K])) > (sm[a+K-1]+sm[b+K-1]-sm[a-1]-sm[b-1]))
		{
			a = hpref[i-K]-K+1;
			b = i-K+1;
		}
	}
	cout << a << " " << b << endl;
}