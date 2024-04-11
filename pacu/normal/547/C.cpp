#include <iostream>
#include <vector>
using namespace std;

vector<int> primes[200000];
int cnt[500001];

int A[200000];
bool cont[200000];
long long relprime;

void addrem(int i,int inc)
{
	int dif = 0;
	int pval;
	int dir;
	for(int j=0;j<(1<<primes[i].size());j++)
	{
		pval = 1;
		dir = 1;
		for(int k=0;k<primes[i].size();k++)
			if(j&(1<<k))
				pval *= primes[i][k], dir = -dir;
		if(inc == -1) cnt[pval]--;
		relprime += cnt[pval]*dir*inc;
		if(inc == 1) cnt[pval]++;
//		cout << pval << ": " << cnt[pval] << '\n';
	}
}

void getPrimes(int i)
{
	for(int j=2;j*j<=A[i];j++)
	{
		if(!(A[i]%j))
		{
			primes[i].push_back(j);
			while(!(A[i]%j))
				A[i] /= j;
		}
	}
	if(A[i] > 1)
		primes[i].push_back(A[i]);
}


int main()
{
	ios::sync_with_stdio(0);
	int N,Q;
	cin >> N >> Q;
	relprime = 0;
	for(int i=0;i<N;i++)
	{
		cin >> A[i];
		getPrimes(i);
	}
	int q;
	for(int i=0;i<Q;i++)
	{
		cin >> q;
		q--;
		if(cont[q])
			addrem(q,-1);
		else
			addrem(q,+1);
		cont[q] = 1-cont[q];
		cout << relprime << '\n';
	}
}